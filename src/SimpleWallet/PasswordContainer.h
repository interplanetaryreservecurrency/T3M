
#pragma once

#include <string>

namespace Tools
{
  class PasswordContainer
  {
  public:
    static const size_t max_password_size = 1024;

    PasswordContainer();
    PasswordContainer(std::string&& password);
    PasswordContainer(PasswordContainer&& rhs);
    ~PasswordContainer();

    void clear();
    bool empty() const { return m_empty; }
    const std::string& password() const { return m_password; }
    void password(std::string&& val) { m_password = std::move(val); m_empty = false; }
    bool read_password();

  private:
    bool read_from_file();
    bool read_from_tty();

  private:
    bool m_empty;
    std::string m_password;
  };
}
