/*
 * Lv2Manager.cpp
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

#include "extensionsystem/ExtensionManager.h"
#include "IPluginProvider.h"
#include "PluginManager.h"

using namespace Unison;
using namespace ExtensionSystem;

namespace Core {

// There is only one of these...
PluginManager* PluginManager::m_instance = static_cast<PluginManager*>(NULL);

PluginManager::PluginManager()
{
  qDebug( "Initializing Plugin Manager" );
}


PluginManager::~PluginManager ()
{}


PluginDescriptorPtr PluginManager::descriptor (const QString uniqueId)
{
  ExtensionManager * em = ExtensionManager::instance();
  QList<IPluginProvider*> providers = em->getObjects<IPluginProvider>();

  foreach(IPluginProvider* pp, providers) {
    if (PluginDescriptorPtr desc = pp->descriptor(uniqueId)) {
      return desc;
    }
  }

  return PluginDescriptorPtr(NULL);
}

} // Core

// vim: ts=8 sw=2 sts=2 et sta noai
