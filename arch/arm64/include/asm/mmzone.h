#ifndef __ASM_ARM64_MMZONE_H_
#define __ASM_ARM64_MMZONE_H_

#ifdef CONFIG_NUMA

#include <linux/mmdebug.h>
#include <linux/types.h>

#include <asm/smp.h>
#include <asm/numa.h>

extern struct pglist_data *node_data[];

#define NODE_DATA(nid)		(node_data[(nid)])

#endif /* CONFIG_NUMA */
#endif /* __ASM_ARM64_MMZONE_H_ */
