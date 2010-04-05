/*
 * ControlBuffer.h
 *
 * Copyright (c) 2010 Paul Giblock <pgib/at/users.sourceforge.net>
 *
 * This file is part of Unison - http://unison.sourceforge.net
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program (see COPYING); if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA.
 *
 */

#ifndef CONTROL_BUFFER_H
#define CONTROL_BUFFER_H

#include "unison/Buffer.h"

namespace Unison
{


class ControlBuffer : public Buffer
{
  public:
    ControlBuffer (BufferProvider &provider) :
      Buffer(provider),
      m_data(0.0f)
    {}

    ~ControlBuffer()
    {}

    PortType type () {
      return CONTROL_PORT;
    }

    void* data()
    {
      return &m_data;
    }

    const void* data() const
    {
      return &m_data;
    }

  protected:
    float m_data;
};

} // Unison


#endif

// vim: et ts=8 sw=2 sts=2 noai
