/*
 * Copyright (C) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdint.h>
#ifndef _FS_UTIL_H
#define _FS_UTIL_H

#define pwarn  printf
#define pfatal printf
#define perr   printf

#endif

/*
 * le16dec(),le32dec(),le16enc(),le32enc()
 * Link： https://github.com/freebsd/freebsd-src/
 * Path:  freebsd-src/contrib/elftoolchain/libpe/_libpe.h
 */
/* Encode/Decode macros */
#if defined(ELFTC_NEED_BYTEORDER_EXTENSIONS)
static  __inline uint16_t
le16dec(const void *pp)
{
	unsigned char const *p = (unsigned char const *)pp;

	return ((p[1] << 8) | p[0]);
}

static __inline uint32_t
le32dec(const void *pp)
{
	unsigned char const *p = (unsigned char const *)pp;

	return ((p[3] << 24) | (p[2] << 16) | (p[1] << 8) | p[0]);
}

static __inline void
le16enc(void *pp, uint16_t u)
{
	unsigned char *p = (unsigned char *)pp;

	p[0] = u & 0xff;
	p[1] = (u >> 8) & 0xff;
}

static __inline void
le32enc(void *pp, uint32_t u)
{
	unsigned char *p = (unsigned char *)pp;

	p[0] = u & 0xff;
	p[1] = (u >> 8) & 0xff;
	p[2] = (u >> 16) & 0xff;
	p[3] = (u >> 24) & 0xff;
}
#endif	/* ELFTC_NEED_BYTEORDER_EXTENSIONS */

/*
 * roundup2
 * Link： https://github.com/freebsd/freebsd-src/
 * Path:  freebsd-src/tools/build/cross-build/include/common/sys/param.h
 */
#ifndef roundup2
#define roundup2(x, y) \
	(((x) + ((y)-1)) & (~((y)-1))) /* if y is powers of two */
#endif // _FS_UTIL_H