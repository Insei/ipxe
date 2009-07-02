#ifndef _GPXE_IB_QSET_H
#define _GPXE_IB_QSET_H

/** @file
 *
 * Infiniband queue sets
 *
 */

FILE_LICENCE ( GPL2_OR_LATER );

#include <stdint.h>
#include <gpxe/infiniband.h>

/** An Infiniband queue set */
struct ib_queue_set {
	/** Completion queue */
	struct ib_completion_queue *cq;
	/** Queue pair */
	struct ib_queue_pair *qp;
	/** Receive work queue maximum fill level */
	unsigned int recv_max_fill;
	/** Receive packet length */
	size_t recv_pkt_len;
};

extern int ib_create_qset ( struct ib_device *ibdev,
			    struct ib_queue_set *qset, unsigned int num_cqes,
			    struct ib_completion_queue_operations *cq_op,
			    unsigned int num_send_wqes,
			    unsigned int num_recv_wqes, size_t recv_pkt_len,
			    unsigned long qkey );
extern void ib_qset_refill_recv ( struct ib_device *ibdev,
				  struct ib_queue_set *qset );
extern void ib_destroy_qset ( struct ib_device *ibdev,
			      struct ib_queue_set *qset );

#endif /* _GPXE_IB_QSET_H */