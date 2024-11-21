/* SPDX-License-Identifier: GPL-2.0 */

/* Only support IPv6 as the sequence number now.*/
#ifndef _WG_SEQUENCE_H
#define _WG_SEQUENCE_H

#include "linux/in6.h"
#include "net/ipv6.h"

void in6_sequence_increment(struct in6_addr *sequence);
int in6_sequence_compare(const struct in6_addr *sequence1, const struct in6_addr *sequence2);
void in6_sequence_to_string(const struct in6_addr *sequence, char *buf, size_t len);



#endif // _WG_SEQUENCE_H