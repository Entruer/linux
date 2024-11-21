/* SPDX-License-Identifier: GPL-2.0 */

#include "sequence.h"

void in6_sequence_increment(struct in6_addr *sequence)
{
	u32 *seq = sequence->in6_u.u6_addr32;
	int i;

	for (i = 3; i >= 0; i--) {
		seq[i] = cpu_to_be32(be32_to_cpu(seq[i]) + 1);
		if (seq[i])
			break;
	}
}

int in6_sequence_compare(const struct in6_addr *sequence1,
			 const struct in6_addr *sequence2)
{
    const u32 *seq1 = sequence1->in6_u.u6_addr32;
    const u32 *seq2 = sequence2->in6_u.u6_addr32;
    int i;

    for (i = 0; i < 4; i++) {
        if (be32_to_cpu(seq1[i]) < be32_to_cpu(seq2[i]))
            return -1;
        if (be32_to_cpu(seq1[i]) > be32_to_cpu(seq2[i]))
            return 1;
    }
    return 0;
}

void in6_sequence_to_string(const struct in6_addr *sequence, char *buf, size_t len)
{
    const u32 *seq = sequence->in6_u.u6_addr32;
    snprintf(buf, len, "%08x,%08x,%08x,%08x", be32_to_cpu(seq[3]), be32_to_cpu(seq[2]), be32_to_cpu(seq[1]), be32_to_cpu(seq[0]));
}