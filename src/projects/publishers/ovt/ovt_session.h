#pragma once

#include <base/info/media_track.h>
#include <base/ovsocket/socket.h>
#include <base/publisher/session.h>

class OvtSession : public Session
{
public:
	static std::shared_ptr<OvtSession> Create(const std::shared_ptr<Application> &application,
											  const std::shared_ptr<Stream> &stream,
											  uint32_t ovt_session_id,
											  const std::shared_ptr<ov::Socket> &connector);

	OvtSession(const SessionInfo &session_info,
			const std::shared_ptr<Application> &application,
			const std::shared_ptr<Stream> &stream,
			const std::shared_ptr<ov::Socket> &connector);
	~OvtSession() override;

	bool Start() override;
	bool Stop() override;

	bool SendOutgoingData(uint32_t packet_type, const std::shared_ptr<ov::Data> &packet) override;
	void OnPacketReceived(const std::shared_ptr<info::SessionInfo> &session_info,
						const std::shared_ptr<const ov::Data> &data) override;


	const std::shared_ptr<ov::Socket> GetConnector();

private:
	std::shared_ptr<ov::Socket>		_connector;
	bool 							_sent_ready;
};