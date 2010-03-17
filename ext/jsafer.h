/*
   +----------------------------------------------------------------------+
   | Copyright (c) 2002-2009 J Smith <dark.panda@gmail.com>               |
   | Crypto++ sources (not included) copyright (c) 1995-2009 Wei Dai      |
   +----------------------------------------------------------------------+
   | Check out COPYING for the exact license.                             |
   +----------------------------------------------------------------------+

$Id: $
*/

#ifndef __JSAFER_H__
#define __JSAFER_H__

#include "jconfig.h"

#if ENABLED_SAFER_K_CIPHER || ENABLED_SAFER_SAFER_SK_CIPHER

#include "jcipher_t.h"

// Crypto++ headers...

#include "safer.h"

using namespace CryptoPP;

#if ENABLED_SAFER_K_CIPHER
class JSAFER_K : public JCipher_Template<SAFER_K_Info, SAFER_K_CIPHER, 6, 1, 13>
{
	protected:
		BlockCipher* getEncryptionObject();
		BlockCipher* getDecryptionObject();
};
#endif

#if ENABLED_SAFER_SK_CIPHER
class JSAFER_SK : public JCipher_Template<SAFER_SK_Info, SAFER_SK_CIPHER, 6, 1, 13>
{
	protected:
		BlockCipher* getEncryptionObject();
		BlockCipher* getDecryptionObject();
};
#endif

#endif
#endif
