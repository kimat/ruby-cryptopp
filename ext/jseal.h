
/*
 * Copyright (c) 2002-2014 J Smith <dark.panda@gmail.com>
 * Crypto++ copyright (c) 1995-2013 Wei Dai
 * See MIT-LICENSE for the extact license
 */

#ifndef __JSEAL_H__
#define __JSEAL_H__

#include "jconfig.h"

#if ENABLED_SEAL_LITTLE_ENDIAN_CIPHER || ENABLED_SEAL_BIG_ENDIAN_CIPHER

#include "jstream_t.h"

// Crypto++ headers...

#include "seal.h"

using namespace CryptoPP;

#if ENABLED_SEAL_LITTLE_ENDIAN_CIPHER
class JSEAL_LE : public JStream_Template<SEAL_Info<LittleEndian>, SEAL_LITTLE_ENDIAN_CIPHER>
{
  protected:
    SymmetricCipher* getEncryptionObject();
    SymmetricCipher* getDecryptionObject();
};
#endif

#if ENABLED_SEAL_BIG_ENDIAN_CIPHER
class JSEAL_BE : public JStream_Template<SEAL_Info<BigEndian>, SEAL_BIG_ENDIAN_CIPHER>
{
  protected:
    SymmetricCipher* getEncryptionObject();
    SymmetricCipher* getDecryptionObject();
};
#endif

#endif
#endif
