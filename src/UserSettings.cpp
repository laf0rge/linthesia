// -*- mode: c++; coding: utf-8 -*-

// Linthesia

// Copyright (c) 2007 Nicholas Piegdon
// Adaptation to GNU/Linux by Oscar Aceña
// Adaptation from gconfmm to GSettings by Harald Welte
// See COPYING for license information

#include <giomm/settings.h>

#include "StringUtil.h"

using namespace std;

namespace UserSetting {

  static Glib::RefPtr<Gio::Settings> m_settings;

  void Initialize(const string &app_name) {
    if (m_settings)
      return;

    m_settings = Gio::Settings::create("org.example.linthesia");
    if (!m_settings)
      return;
  }

  string Get(const string &setting, const string &default_value) {
    if (!m_settings)
      return default_value;

    string result = m_settings->get_string(setting);
    if (result.empty())
      return default_value;

    return result;
  }

  void Set(const string &setting, const string &value) {
    if (!m_settings)
      return;

    m_settings->set_string(setting, value);
  }

}; // End namespace
