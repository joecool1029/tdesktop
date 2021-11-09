/*
This file is part of Telegram Desktop,
the official desktop application for the Telegram messaging service.

For license and copyright information please follow this link:
https://github.com/telegramdesktop/tdesktop/blob/master/LEGAL
*/
#pragma once

class PeerData;

namespace Main {

class Session;

class SendAsPeers final {
public:
	explicit SendAsPeers(not_null<Session*> session);

	void refresh(not_null<PeerData*> peer);
	[[nodiscard]] const std::vector<not_null<PeerData*>> &list(
		not_null<PeerData*> peer);
	[[nodiscard]] rpl::producer<not_null<PeerData*>> updated() const;

private:
	void request(not_null<PeerData*> peer);

	const not_null<Session*> _session;
	const std::vector<not_null<PeerData*>> _onlyMe;

	base::flat_map<
		not_null<PeerData*>,
		std::vector<not_null<PeerData*>>> _lists;
	base::flat_map<not_null<PeerData*>, crl::time> _lastRequestTime;

	rpl::event_stream<not_null<PeerData*>> _updates;

};

} // namespace Main
