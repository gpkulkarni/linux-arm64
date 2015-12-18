#ifndef _ASM_NUMA_H
#define _ASM_NUMA_H

#include <linux/nodemask.h>
#include <asm/topology.h>

#ifdef CONFIG_NUMA

#define NR_NODE_MEMBLKS		(MAX_NUMNODES * 2)
#define ZONE_ALIGN (1UL << (MAX_ORDER + PAGE_SHIFT))

/* currently, arm64 implements flat NUMA topology */
#define parent_node(node)	(node)

extern int __node_distance(int from, int to);
#define node_distance(a, b) __node_distance(a, b)

/* dummy definitions for pci functions */
#define pcibus_to_node(node)	0
#define cpumask_of_pcibus(bus)	0

extern int cpu_to_node_map[NR_CPUS];
extern nodemask_t numa_nodes_parsed __initdata;

/* Mappings between node number and cpus on that node. */
extern cpumask_var_t node_to_cpumask_map[MAX_NUMNODES];
extern void numa_clear_node(unsigned int cpu);
#ifdef CONFIG_DEBUG_PER_CPU_MAPS
extern const struct cpumask *cpumask_of_node(int node);
#else
/* Returns a pointer to the cpumask of CPUs on Node 'node'. */
static inline const struct cpumask *cpumask_of_node(int node)
{
	return node_to_cpumask_map[node];
}
#endif

void __init arm64_numa_init(void);
int __init numa_add_memblk(int nodeid, u64 start, u64 end);
void __init numa_set_distance(int from, int to, int distance);
void __init numa_reset_distance(void);
void numa_store_cpu_info(unsigned int cpu);
#else	/* CONFIG_NUMA */
static inline void numa_store_cpu_info(unsigned int cpu)		{ }
static inline void arm64_numa_init(void)		{ }
#endif	/* CONFIG_NUMA */
#endif	/* _ASM_NUMA_H */
