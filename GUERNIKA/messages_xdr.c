/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "messages.h"

bool_t
xdr_tupla (XDR *xdrs, tupla *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->clave))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->valor1, 255,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->valor2))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->valor3))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_double_key (XDR *xdrs, double_key *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->key1))
		 return FALSE;
	 if (!xdr_int (xdrs, &objp->key2))
		 return FALSE;
	return TRUE;
}
