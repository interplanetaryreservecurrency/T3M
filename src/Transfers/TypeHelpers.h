
#pragma once

#include "ITransaction.h"
#include <functional>
#include <cstring>

namespace CryptoNote {

inline bool operator==(const AccountPublicAddress &_v1, const AccountPublicAddress &_v2) {
  return memcmp(&_v1, &_v2, sizeof(AccountPublicAddress)) == 0;
}

}

namespace std {

template<>
struct hash < CryptoNote::AccountPublicAddress > {
  size_t operator()(const CryptoNote::AccountPublicAddress& val) const {
    size_t spend = *(reinterpret_cast<const size_t*>(&val.spendPublicKey));
    size_t view = *(reinterpret_cast<const size_t*>(&val.viewPublicKey));
    return spend ^ view;
  }
};

}
