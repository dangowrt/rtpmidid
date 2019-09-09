/**
 * Real Time Protocol Music Instrument Digital Interface Daemon
 * Copyright (C) 2019 David Moreno Montero <dmoreno@coralbits.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <string>
#include <memory>
#include <vector>

struct AvahiClient;
typedef struct AvahiClient AvahiClient;
typedef struct AvahiPoll AvahiPoll;
typedef struct AvahiEntryGroup AvahiEntryGroup;

namespace rtpmidid {
  struct announcement_t {
    std::string name;
    int port;
  };

  class mdns_rtpmidi {
  public:
    std::unique_ptr<AvahiPoll> poller_adapter;
    AvahiClient *client;
    AvahiEntryGroup *group;
    std::vector<announcement_t> announcements;

    mdns_rtpmidi();
    ~mdns_rtpmidi();
    void handle_connected();
    void announce_rtpmidi(const std::string &name, const int32_t port);
    void unannounce_rtpmidi(const std::string &name, const int32_t port);
  };
}
