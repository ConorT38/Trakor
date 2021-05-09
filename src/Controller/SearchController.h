/*
 * SearchController.h
 *
 *  Created on: 5 May 2021
 *      Author: conor
 */

#ifndef CONTROLLER_SEARCHCONTROLLER_H_
#define CONTROLLER_SEARCHCONTROLLER_H_

#include <algorithm>

#include <pistache/endpoint.h>
#include <pistache/http.h>
#include <pistache/router.h>

using namespace Pistache;

class SearchController
{

	std::shared_ptr<Http::Endpoint> httpEndpoint;
	Rest::Router router;

public:
	explicit SearchController(Address address) : httpEndpoint(std::make_shared<Http::Endpoint>(address))
	{
	}

	void init(size_t threads = 2)
	{
		auto options = Http::Endpoint::options().threads(
			static_cast<int>(threads));
		httpEndpoint->init(options);
		setupRoutes();
	}

	void start()
	{
		httpEndpoint->setHandler(router.handler());
		httpEndpoint->serve();
	}

private:
	void setupRoutes()
	{
		using namespace Rest;

		Routes::Get(router, "/search/:searchTerm",
					Routes::bind(&SearchController::doGetSearchResult, this));
	}

	void doGetSearchResult(const Rest::Request &request,
						   Http::ResponseWriter response)
	{
		auto searchTerm = request.param(":searchTerm").as<std::string>();
		/*
		 * TODO: Get Search term results from cache/db.
		 */
		response.send(Http::Code::Ok, searchTerm);
	}
};

#endif /* CONTROLLER_SEARCHCONTROLLER_H_ */
