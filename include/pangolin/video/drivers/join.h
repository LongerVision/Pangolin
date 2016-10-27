/* This file is part of the Pangolin Project.
 * http://github.com/stevenlovegrove/Pangolin
 *
 * Copyright (c) 2014 Steven Lovegrove
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <pangolin/video/video.h>

namespace pangolin
{

class PANGOLIN_EXPORT JoinVideo
    : public VideoInterface, public VideoFilterInterface
{
public:
    JoinVideo(std::vector<std::unique_ptr<VideoInterface>> &src);

    ~JoinVideo();

    size_t SizeBytes() const;

    const std::vector<StreamInfo>& Streams() const;

    void Start();

    void Stop();

    bool Sync(int64_t tolerance_us, int64_t expected_delta_us = 0);

    bool GrabNext( unsigned char* image, bool wait = true );

    bool GrabNewest( unsigned char* image, bool wait = true );

    std::vector<VideoInterface*>& InputStreams();

protected:
    std::vector<std::unique_ptr<VideoInterface>> storage;
    std::vector<VideoInterface*> src;
    std::vector<StreamInfo> streams;
    size_t size_bytes;
    int64_t sync_tolerance_us;
    int64_t expected_timestamp_delta_us;
};


}
