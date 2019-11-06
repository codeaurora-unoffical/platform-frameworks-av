/*
 * Copyright (C) 2013 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef PLAYER_SERVICE_MEDIA_HTTP_H_

#define PLAYER_SERVICE_MEDIA_HTTP_H_

#include <datasource/MediaHTTP.h>
#include <media/stagefright/foundation/AString.h>

namespace android {

struct MediaHTTPConnection;

// MediaHTTP implementation which works on MediaPlayerService.
// Supports OMA(forword-lock) stream.
struct PlayerServiceMediaHTTP : public MediaHTTP {
    PlayerServiceMediaHTTP(const sp<MediaHTTPConnection> &conn);

protected:
    virtual ~PlayerServiceMediaHTTP();

    virtual sp<DecryptHandle> DrmInitialization(const char* mime);

private:
    sp<DecryptHandle> mDecryptHandle;
    DrmManagerClient *mDrmManagerClient;

    void clearDRMState_l();

    DISALLOW_EVIL_CONSTRUCTORS(PlayerServiceMediaHTTP);
};

}  // namespace android

#endif  // PLAYER_SERVICE_MEDIA_HTTP_H_
