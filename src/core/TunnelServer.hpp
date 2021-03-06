/*
 * @name BookFiler Module - SSH
 * @author Branden Lee
 * @version 1.00
 * @license MIT
 * @brief SSH module for BookFiler™ applications.
 */

#ifndef BOOKFILER_MODULE_SSH_TUNNEL_SERVER_H
#define BOOKFILER_MODULE_SSH_TUNNEL_SERVER_H

// config
#include "config.hpp"

// C++11
#include <functional>
#include <iostream>
#include <memory>
#include <queue>

/* rapidjson v1.1 (2016-8-25)
 * Developed by Tencent
 * License: MITs
 */
#include <rapidjson/document.h>
#include <rapidjson/filewritestream.h>
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/reader.h> // rapidjson::ParseResult
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

/* boost 1.72.0
 * License: Boost Software License (similar to BSD and MIT)
 */
#include <boost/asio.hpp>
#include <boost/config.hpp>

// Local Project
#include "TunnelServerListener.hpp"

/*
 * bookfiler - ssh
 * ssh utilities. The main feature is the ssh tunnel for mysql
 */
namespace bookfiler {
namespace ssh {

class TunnelServerImpl : public TunnelServer {
private:
  std::shared_ptr<rapidjson::Value> settingsDoc;
  std::shared_ptr<ServerState> serverState;
  std::shared_ptr<boost::asio::io_context> ioContext;
  std::shared_ptr<ListenerImpl> listener;
  std::vector<std::thread> threadList;

public:
  TunnelServerImpl(
      std::map<std::string, bookfiler::port::newForwardingServerType> map_);
  ~TunnelServerImpl();
  int setSettingsDoc(std::shared_ptr<rapidjson::Value>);
  int run();
  void runIoContext();
};

} // namespace port
} // namespace bookfiler

#endif
// end BOOKFILER_MODULE_PORT_FORWARDING_SERVER_Hs
