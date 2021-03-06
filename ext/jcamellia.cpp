
/*
 * Copyright (c) 2002-2014 J Smith <dark.panda@gmail.com>
 * Crypto++ copyright (c) 1995-2013 Wei Dai
 * See MIT-LICENSE for the extact license
 */

#include "jcamellia.h"

#if ENABLED_CAMELLIA_CIPHER

BlockCipher* JCamellia::getEncryptionObject()
{
  return new CamelliaEncryption((byte*) itsKey.data(), itsKeylength);
}

BlockCipher* JCamellia::getDecryptionObject()
{
  return new CamelliaDecryption((byte*) itsKey.data(), itsKeylength);
}

#endif
