/*
 * (C) Copyright 2013 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef __MEDIA_PIPELINE_HPP__
#define __MEDIA_PIPELINE_HPP__

#include "MediaObjectImpl.hpp"
#include "MediaHandler.hpp"
#include <common/MediaSet.hpp>

namespace kurento
{

class MediaElement;
class Mixer;

class MediaPipeline : public MediaObjectImpl,
		      public MediaPipelineType,
		      public std::enable_shared_from_this<MediaPipeline>
{

public:
  MediaPipeline (const Params &params = defaultParams) throw (MediaServerException);
  ~MediaPipeline() throw();

  std::shared_ptr<MediaElement> createMediaElement(const std::string& elementType, const Params& params = defaultParams)
                                                  throw (MediaServerException);
  std::shared_ptr<Mixer> createMediaMixer(const std::string& mixerType, const Params& params = defaultParams)
                                          throw (MediaServerException);

  GstElement *pipeline;

private:
  void init ();

  class StaticConstructor
  {
  public:
    StaticConstructor();
  };

  static StaticConstructor staticConstructor;
};

} // kurento

#endif /* __MEDIA_PIPELINE_HPP__ */
