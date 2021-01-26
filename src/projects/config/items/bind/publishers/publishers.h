//==============================================================================
//
//  OvenMediaEngine
//
//  Created by Hyunjun Jang
//  Copyright (c) 2019 AirenSoft. All rights reserved.
//
//==============================================================================
#pragma once

#include "./publisher.h"
#include "./webrtc.h"

namespace cfg
{
	namespace bind
	{
		namespace pub
		{
			struct Publishers : public Item
			{
			protected:
				Publisher<cmn::SingularPort> _ovt{"9000/tcp"};
				Publisher<cmn::SingularPort> _rtmp{"1935/tcp"};
				Publisher<cmn::SingularPort> _hls{"80/tcp", "443/tcp"};
				Publisher<cmn::SingularPort> _dash{"80/tcp", "443/tcp"};
				Publisher<cmn::SingularPort> _thumbnail{"80/tcp", "443/tcp"};

				Webrtc _webrtc{"3333/tcp", "3334/tcp"};

			public:
				CFG_DECLARE_REF_GETTER_OF(GetOvt, _ovt)
				CFG_DECLARE_REF_GETTER_OF(GetRtmp, _rtmp)
				CFG_DECLARE_REF_GETTER_OF(GetHls, _hls)
				CFG_DECLARE_REF_GETTER_OF(GetDash, _dash)
				CFG_DECLARE_REF_GETTER_OF(GetWebrtc, _webrtc)
				CFG_DECLARE_REF_GETTER_OF(GetThumbnail, _thumbnail)

			protected:
				void MakeList() override
				{
					Register<Optional>("OVT", &_ovt);
					Register<Optional>("RTMP", &_rtmp);
					Register<Optional>("HLS", &_hls);
					Register<Optional>("DASH", &_dash);
					Register<Optional>("WebRTC", &_webrtc);
					Register<Optional>("Thumbnail", &_thumbnail);
				};
			};
		}  // namespace pub
	}	   // namespace bind
}  // namespace cfg