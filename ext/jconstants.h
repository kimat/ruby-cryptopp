/*
   +----------------------------------------------------------------------+
   | Copyright (c) 2002-2009 J Smith <dark.panda@gmail.com>               |
   | Crypto++ sources (not included) copyright (c) 1995-2009 Wei Dai      |
   +----------------------------------------------------------------------+
   | Check out COPYING for the exact license.                             |
   +----------------------------------------------------------------------+

$Id: $
*/

#ifndef __JCONSTANTS_H__
#define __JCONSTANTS_H__

using namespace CryptoPP;

// test if word64 is available for SHARK, SHA-384, SHA-512 and Tiger.

#if defined(__GNUC__) || defined(__MWERKS__) || defined(_MSC_VER) || defined(__BCPLUSPLUS__)
#define WORD64_AVAILABLE
#endif


// Cipher types used in JCipher and JStream...

enum CipherEnum {
	UNKNOWN_CIPHER = -1,

	// Stream ciphers...

	ARC4_CIPHER,
	PANAMA_LITTLE_ENDIAN_CIPHER,
	PANAMA_BIG_ENDIAN_CIPHER,
	MARC4_CIPHER,
	SEAL_LITTLE_ENDIAN_CIPHER,
	SEAL_BIG_ENDIAN_CIPHER,

	// Block Ciphers...

	THREEWAY_CIPHER,
	AES_CIPHER,
	BLOWFISH_CIPHER,
	CAST128_CIPHER,
	CAST256_CIPHER,
	DES_CIPHER,
	DES_EDE2_CIPHER,
	DES_EDE3_CIPHER,
	DES_XEX3_CIPHER,
	DIAMOND2_CIPHER,
	DIAMOND2_LITE_CIPHER,
	GOST_CIPHER,
	IDEA_CIPHER,
	MARS_CIPHER,
	RC2_CIPHER,
	RC5_CIPHER,
	RC6_CIPHER,
	SAFER_K_CIPHER,
	SAFER_SK_CIPHER,
	SERPENT_CIPHER,
	SKIPJACK_CIPHER,
	SQUARE_CIPHER,
	TEA_CIPHER,
	TWOFISH_CIPHER,
	SHARK_CIPHER,

	// Ciphers from Crypto++ 5.2.1...

	CAMELLIA_CIPHER,
	SHACAL2_CIPHER
};

#define PANAMA_CIPHER PANAMA_LITTLE_ENDIAN_CIPHER
#define SEAL_CIPHER SEAL_BIG_ENDIAN_CIPHER
#define RIJNDAEL_CIPHER AES_CIPHER

// This is used to determine if we're using a stream
// cipher or a block cipher. If its <= TYPE_OF_CIPHER,
// it's a stream cipher; otherwise, it's a block cipher...

#define IS_BLOCK_CIPHER(x) (x >= THREEWAY_CIPHER && x <= SHACAL2_CIPHER ? true : false)
#define IS_STREAM_CIPHER(x) (x >= ARC4_CIPHER && x <= SEAL_BIG_ENDIAN_CIPHER ? true : false)
#define VALID_CIPHER(x) (x >= ARC4_CIPHER && x <= SHACAL2_CIPHER ? true : false)


// Block cipher modes used in JCipher...

enum ModeEnum {
	ECB_MODE,
	CBC_MODE,
	CBC_CTS_MODE,
	CFB_MODE,
	CTR_MODE,
	OFB_MODE
};

#define VALID_MODE(x) (x >= ECB_MODE && x <= OFB_MODE ? true : false)


// Block cipher padding used in JCipher...

enum PaddingEnum {
	NO_PADDING = StreamTransformationFilter::NO_PADDING,
	ZEROS_PADDING = StreamTransformationFilter::ZEROS_PADDING,
	PKCS_PADDING = StreamTransformationFilter::PKCS_PADDING,
	ONE_AND_ZEROS_PADDING = StreamTransformationFilter::ONE_AND_ZEROS_PADDING,
	DEFAULT_PADDING = StreamTransformationFilter::DEFAULT_PADDING
};

#define VALID_PADDING(x) (x >= NO_PADDING && x <= DEFAULT_PADDING ? true : false)


// Hashes... and HMAC stuff, too...

enum HashEnum {
	// These are checksums, not cryptographic hashes...

	ADLER32_CHECKSUM,
	CRC32_CHECKSUM,

	// These are hashes. And message digests. ...

	HAVAL_HASH,
	HAVAL3_HASH,
	HAVAL4_HASH,
	HAVAL5_HASH,
	MD2_HASH,
	MD4_HASH,
	MD5_HASH,
	PANAMA_LITTLE_ENDIAN_HASH,
	PANAMA_BIG_ENDIAN_HASH,
	RIPEMD160_HASH,
	SHA1_HASH,
	SHA256_HASH,
	SHA384_HASH,
	SHA512_HASH,
	TIGER_HASH,

	// These are for HMAC hashes...

	MD2_HMAC,
	MD4_HMAC,
	MD5_HMAC,
	RIPEMD160_HMAC,
	SHA1_HMAC,
	SHA256_HMAC,
	SHA384_HMAC,
	SHA512_HMAC,
	TIGER_HMAC,

	// Newer hashes and HMACs from Crypto++ 5.2.1...

	RIPEMD128_HASH,
	RIPEMD256_HASH,
	RIPEMD320_HASH,
	WHIRLPOOL_HASH,

	RIPEMD128_HMAC,
	RIPEMD256_HMAC,
	RIPEMD320_HMAC,
	WHIRLPOOL_HMAC
};

#define PANAMA_HASH PANAMA_LITTLE_ENDIAN_HASH
#define PANAMA_HMAC PANAMA_LITTLE_ENDIAN_HMAC

// this is to figure out if we're dealing
// with a HMAC or a regular hash...

#define IS_HMAC(x) \
	(((x > TIGER_HASH && x < RIPEMD128_HASH) || x >= RIPEMD128_HMAC) ? true : false)
#define IS_NON_HMAC(x) \
	((x <= TIGER_HASH || (x >= RIPEMD128_HASH && x <= WHIRLPOOL_HASH)) ? true : false)


// random number generators...

enum RNGEnum {
	NONBLOCKING_RNG,
	BLOCKING_RNG,
	RAND_RNG
};

#define VALID_RNG(x) (x >= NONBLOCKING_RNG && x <= RAND_RNG ? true : false)

#ifdef NONBLOCKING_RNG_AVAILABLE
	#define DEFAULT_RNG NONBLOCKING_RNG
#elif defined(BLOCKING_RNG_AVAILABLE)
	#define DEFAULT_RNG BLOCKING_RNG
#else
	#define DEFAULT_RNG RAND_RNG
#endif

#endif