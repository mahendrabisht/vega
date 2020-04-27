/*
 * Note: this file originally auto-generated by mib2c using
 *       version : 12088 $ of $
 *
 * $Id:$
 */
/* standard Net-SNMP includes */
#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>

/* include our parent header */
#include "sessionTable.h"

#include "memdebug.h"

/** @defgroup data_get data_get: Routines to get data
 *
 * TODO:230:M: Implement sessionTable get routines.
 * TODO:240:M: Implement sessionTable mapping routines (if any).
 *
 * These routine are used to get the value for individual objects. The
 * row context is passed, along with a pointer to the memory where the
 * value should be copied.
 *
 * @{
 */
/**********************************************************************
 **********************************************************************
 ***
 *** Table sessionTable
 ***
 **********************************************************************
 **********************************************************************/
/*
 * VEGA-PPP-MIB::sessionTable is subid 1 of vegaPPPSessions.
 * Its status is Current.
 * OID: .1.3.6.1.4.1.8072.100.2.1, length: 10
*/

/* ---------------------------------------------------------------------
 * TODO:200:r: Implement sessionTable data context functions.
 */
/*
 * sessionTable_allocate_data
 *
 * Purpose: create new sessionTable_data->
 */
sessionTable_data *
sessionTable_allocate_data(void)
{
    sessionTable_data *rtn = SNMP_MALLOC_TYPEDEF(sessionTable_data);

    DEBUGMSGTL(("verbose:sessionTable:sessionTable_allocate_data","called\n"));

    if(NULL == rtn) {
        snmp_log(LOG_ERR, "unable to malloc memory for new "
                 "sessionTable_data->\n");
    }

		memset(rtn, 0, sizeof(*rtn));

    return rtn;
} /* sessionTable_allocate_data */

/*
 * sessionTable_release_data
 *
 * Purpose: release sessionTable data->
 */
void
sessionTable_release_data(sessionTable_data *data)
{
    DEBUGMSGTL(("verbose:sessionTable:sessionTable_release_data","called\n"));

		if (data->username)
			_free(data->username);

		if (data->calling_sid)
			_free(data->calling_sid);

		if (data->called_sid)
			_free(data->called_sid);

    free(data);
} /* sessionTable_release_data */



/**
 * set mib index(es)
 *
 * @param tbl_idx mib index structure
 * @param sesSID_ptr
 * @param sesSID_ptr_len
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This convenience function is useful for setting all the MIB index
 *  components with a single function call. It is assume that the C values
 *  have already been mapped from their native/rawformat to the MIB format.
 */
int
sessionTable_indexes_set_tbl_idx(sessionTable_mib_index *tbl_idx, char *sesSID_val_ptr,  size_t sesSID_val_ptr_len)
{
    DEBUGMSGTL(("verbose:sessionTable:sessionTable_indexes_set_tbl_idx","called\n"));

    /* sesSID(1)/OCTETSTR/ASN_OCTET_STR/char(char)//L/A/w/e/R/d/h */
    tbl_idx->sesSID_len = sizeof(tbl_idx->sesSID)/sizeof(tbl_idx->sesSID[0]); /* max length */
    /** WARNING: this code might not work for struct sessionTable_data_s */
    /*
     * make sure there is enough space for sesSID data
     */
    if ((NULL == tbl_idx->sesSID) ||
        (tbl_idx->sesSID_len <
         (sesSID_val_ptr_len))) {
        snmp_log(LOG_ERR,"not enough space for value\n");
        return MFD_ERROR;
    }
    tbl_idx->sesSID_len = sesSID_val_ptr_len;
    memcpy( tbl_idx->sesSID, sesSID_val_ptr, sesSID_val_ptr_len* sizeof(sesSID_val_ptr[0]) );


    return MFD_SUCCESS;
} /* sessionTable_indexes_set_tbl_idx */

/**
 * @internal
 * set row context indexes
 *
 * @param reqreq_ctx the row context that needs updated indexes
 *
 * @retval MFD_SUCCESS     : success.
 * @retval MFD_ERROR       : other error.
 *
 * @remark
 *  This function sets the mib indexs, then updates the oid indexs
 *  from the mib index.
 */
int
sessionTable_indexes_set(sessionTable_rowreq_ctx *rowreq_ctx, char *sesSID_val_ptr,  size_t sesSID_val_ptr_len)
{
    DEBUGMSGTL(("verbose:sessionTable:sessionTable_indexes_set","called\n"));

    if(MFD_SUCCESS != sessionTable_indexes_set_tbl_idx(&rowreq_ctx->tbl_idx
                                   , sesSID_val_ptr, sesSID_val_ptr_len
           ))
        return MFD_ERROR;

    /*
     * convert mib index to oid index
     */
    rowreq_ctx->oid_idx.len = sizeof(rowreq_ctx->oid_tmp) / sizeof(oid);
    if(0 != sessionTable_index_to_oid(&rowreq_ctx->oid_idx,
                                    &rowreq_ctx->tbl_idx)) {
        return MFD_ERROR;
    }

    return MFD_SUCCESS;
} /* sessionTable_indexes_set */


/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesIfName
 * sesIfName is subid 2 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.2
 * Description:
name of ppp interface
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is OCTETSTR (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.
 */
/**
 * Extract the current value of the sesIfName data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesIfName_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param sesIfName_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by sesIfName.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*sesIfName_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update sesIfName_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
sesIfName_get( sessionTable_rowreq_ctx *rowreq_ctx, char **sesIfName_val_ptr_ptr, size_t *sesIfName_val_ptr_len_ptr )
{
   int len;
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != sesIfName_val_ptr_ptr) && (NULL != *sesIfName_val_ptr_ptr));
   netsnmp_assert( NULL != sesIfName_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesIfName_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		len = strlen(rowreq_ctx->data->ifname);

    if ((NULL == (* sesIfName_val_ptr_ptr )) ||
        ((* sesIfName_val_ptr_len_ptr ) < len)) {
        /*
         * allocate space for sesIfName data
         */
        (* sesIfName_val_ptr_ptr ) = malloc(len);
        if(NULL == (* sesIfName_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* sesIfName_val_ptr_len_ptr ) = len;
    memcpy( (* sesIfName_val_ptr_ptr ), rowreq_ctx->data->ifname, len);

    return MFD_SUCCESS;
} /* sesIfName_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesUsername
 * sesUsername is subid 3 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.3
 * Description:
session user name
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is OCTETSTR (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.
 */
/**
 * Extract the current value of the sesUsername data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesUsername_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param sesUsername_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by sesUsername.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*sesUsername_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update sesUsername_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
sesUsername_get( sessionTable_rowreq_ctx *rowreq_ctx, char **sesUsername_val_ptr_ptr, size_t *sesUsername_val_ptr_len_ptr )
{
   int len;
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != sesUsername_val_ptr_ptr) && (NULL != *sesUsername_val_ptr_ptr));
   netsnmp_assert( NULL != sesUsername_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesUsername_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		len = strlen(rowreq_ctx->data->username);

    if ((NULL == (* sesUsername_val_ptr_ptr )) ||
        ((* sesUsername_val_ptr_len_ptr ) < len)) {
        /*
         * allocate space for sesIfName data
         */
        (* sesUsername_val_ptr_ptr ) = malloc(len);
        if(NULL == (* sesUsername_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* sesUsername_val_ptr_len_ptr ) = len;
    memcpy( (* sesUsername_val_ptr_ptr ), rowreq_ctx->data->username, len);

		return MFD_SUCCESS;
} /* sesUsername_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesIP
 * sesIP is subid 4 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.4
 * Description:
assigned IP address
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is OCTETSTR (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.
 */
/**
 * Extract the current value of the sesIP data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesIP_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param sesIP_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by sesIP.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*sesIP_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update sesIP_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
sesIP_get( sessionTable_rowreq_ctx *rowreq_ctx, char **sesIP_val_ptr_ptr, size_t *sesIP_val_ptr_len_ptr )
{
   int len = 4;
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != sesIP_val_ptr_ptr) && (NULL != *sesIP_val_ptr_ptr));
   netsnmp_assert( NULL != sesIP_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesIP_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    if ((NULL == (* sesIP_val_ptr_ptr )) ||
        ((* sesIP_val_ptr_len_ptr ) < len)) {
        /*
         * allocate space for sesIfName data
         */
        (* sesIP_val_ptr_ptr ) = malloc(len);
        if(NULL == (* sesIP_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* sesIP_val_ptr_len_ptr ) = len;
    memcpy( (* sesIP_val_ptr_ptr ), &rowreq_ctx->data->peer_addr, len);

    return MFD_SUCCESS;
} /* sesIP_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesType
 * sesType is subid 5 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.5
 * Description:
name of ppp interface
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 * Enum range: 10/16. Values:  other(1), direct(2), gre(3), minimal(4), l2tp(5), pptp(6), l2f(7), udp(8), atmp(9), msdp(10), sixToFour(11), sixOverFour(12), isatap(13), teredo(14)
 *
 * Its syntax is IANAtunnelType (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Extract the current value of the sesType data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesType_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesType_get( sessionTable_rowreq_ctx *rowreq_ctx, u_long * sesType_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesType_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesType_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    (* sesType_val_ptr ) = rowreq_ctx->data->type;

    return MFD_SUCCESS;
} /* sesType_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesState
 * sesState is subid 6 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.6
 * Description:
state of session
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  1      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 * Enum range: 3/8. Values:  starting(1), active(2), finishing(3)
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (u_long)
 */
/**
 * Extract the current value of the sesState data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesState_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesState_get( sessionTable_rowreq_ctx *rowreq_ctx, u_long * sesState_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesState_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesState_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		(* sesState_val_ptr ) = rowreq_ctx->data->state;

    return MFD_SUCCESS;
} /* sesState_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesUptime
 * sesUptime is subid 7 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.7
 * Description:
uptime of session
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is TICKS (based on perltype TICKS)
 * The net-snmp type is ASN_TIMETICKS. The C type decl is u_long (u_long)
 */
/**
 * Extract the current value of the sesUptime data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesUptime_val_ptr
 *        Pointer to storage for a u_long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesUptime_get( sessionTable_rowreq_ctx *rowreq_ctx, u_long * sesUptime_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesUptime_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesUptime_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

    (* sesUptime_val_ptr ) = rowreq_ctx->data->uptime;

    return MFD_SUCCESS;
} /* sesUptime_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesCallingSID
 * sesCallingSID is subid 8 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.8
 * Description:
Calling-Station-ID
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is OCTETSTR (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.
 */
/**
 * Extract the current value of the sesCallingSID data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesCallingSID_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param sesCallingSID_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by sesCallingSID.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*sesCallingSID_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update sesCallingSID_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
sesCallingSID_get( sessionTable_rowreq_ctx *rowreq_ctx, char **sesCallingSID_val_ptr_ptr, size_t *sesCallingSID_val_ptr_len_ptr )
{
   int len;
   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != sesCallingSID_val_ptr_ptr) && (NULL != *sesCallingSID_val_ptr_ptr));
   netsnmp_assert( NULL != sesCallingSID_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesCallingSID_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		len = strlen(rowreq_ctx->data->calling_sid);

    if ((NULL == (* sesCallingSID_val_ptr_ptr )) ||
        ((* sesCallingSID_val_ptr_len_ptr ) < len)) {
        /*
         * allocate space for sesCallingSID data
         */
        (* sesCallingSID_val_ptr_ptr ) = malloc(len);
        if(NULL == (* sesCallingSID_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* sesCallingSID_val_ptr_len_ptr ) = len;
    memcpy( (* sesCallingSID_val_ptr_ptr ), rowreq_ctx->data->calling_sid, len);

    return MFD_SUCCESS;
} /* sesCallingSID_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesCalledSID
 * sesCalledSID is subid 9 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.9
 * Description:
Called-Station-ID
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is OCTETSTR (based on perltype OCTETSTR)
 * The net-snmp type is ASN_OCTET_STR. The C type decl is char (char)
 * This data type requires a length.
 */
/**
 * Extract the current value of the sesCalledSID data->
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesCalledSID_val_ptr_ptr
 *        Pointer to storage for a char variable
 * @param sesCalledSID_val_ptr_len_ptr
 *        Pointer to a size_t. On entry, it will contain the size (in bytes)
 *        pointed to by sesCalledSID.
 *        On exit, this value should contain the data size (in bytes).
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
*
 * @note If you need more than (*sesCalledSID_val_ptr_len_ptr) bytes of memory,
 *       allocate it using malloc() and update sesCalledSID_val_ptr_ptr.
 *       <b>DO NOT</b> free the previous pointer.
 *       The MFD helper will release the memory you allocate.
 *
 * @remark If you call this function yourself, you are responsible
 *         for checking if the pointer changed, and freeing any
 *         previously allocated memory. (Not necessary if you pass
 *         in a pointer to static memory, obviously.)
 */
int
sesCalledSID_get( sessionTable_rowreq_ctx *rowreq_ctx, char **sesCalledSID_val_ptr_ptr, size_t *sesCalledSID_val_ptr_len_ptr )
{
	 int len;

   /** we should have a non-NULL pointer and enough storage */
   netsnmp_assert( (NULL != sesCalledSID_val_ptr_ptr) && (NULL != *sesCalledSID_val_ptr_ptr));
   netsnmp_assert( NULL != sesCalledSID_val_ptr_len_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesCalledSID_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		len = strlen(rowreq_ctx->data->called_sid);

    if ((NULL == (* sesCalledSID_val_ptr_ptr )) ||
        ((* sesCalledSID_val_ptr_len_ptr ) < len)) {
        /*
         * allocate space for sesCalledSID data
         */
        (* sesCalledSID_val_ptr_ptr ) = malloc(len);
        if(NULL == (* sesCalledSID_val_ptr_ptr )) {
            snmp_log(LOG_ERR,"could not allocate memory\n");
            return MFD_ERROR;
        }
    }
    (* sesCalledSID_val_ptr_len_ptr ) = len;
    memcpy( (* sesCalledSID_val_ptr_ptr ), rowreq_ctx->data->called_sid, len);

    return MFD_SUCCESS;
} /* sesCalledSID_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesRxBytes
 * sesRxBytes is subid 10 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.10
 * Description:
Received bytes
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * Extract the current value of the sesRxBytes data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesRxBytes_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesRxBytes_get( sessionTable_rowreq_ctx *rowreq_ctx, U64 * sesRxBytes_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesRxBytes_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesRxBytes_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		sesRxBytes_val_ptr->high = rowreq_ctx->data->rx_gw;
		sesRxBytes_val_ptr->low = rowreq_ctx->data->rx_bytes;

    return MFD_SUCCESS;
} /* sesRxBytes_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesRxPkts
 * sesRxPkts is subid 11 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.11
 * Description:
Received packets
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * Extract the current value of the sesRxPkts data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesRxPkts_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesRxPkts_get( sessionTable_rowreq_ctx *rowreq_ctx, u_long * sesRxPkts_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesRxPkts_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesRxPkts_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		*sesRxPkts_val_ptr = rowreq_ctx->data->rx_pkts;

    return MFD_SUCCESS;
} /* sesRxPkts_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesTxBytes
 * sesTxBytes is subid 12 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.12
 * Description:
Transmitted bytes
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * Extract the current value of the sesTxBytes data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesTxBytes_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesTxBytes_get( sessionTable_rowreq_ctx *rowreq_ctx, U64* sesTxBytes_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesTxBytes_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesTxBytes_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		sesTxBytes_val_ptr->high = rowreq_ctx->data->tx_gw;
		sesTxBytes_val_ptr->low = rowreq_ctx->data->tx_bytes;

    return MFD_SUCCESS;
} /* sesTxBytes_get */

/*---------------------------------------------------------------------
 * VEGA-PPP-MIB::sessionEntry.sesTxPkts
 * sesTxPkts is subid 13 of sessionEntry.
 * Its status is Current, and its access level is ReadOnly.
 * OID: .1.3.6.1.4.1.8072.100.2.1.1.13
 * Description:
Transmitted packets
 *
 * Attributes:
 *   accessible 1     isscalar 0     enums  0      hasdefval 0
 *   readable   1     iscolumn 1     ranges 0      hashint   0
 *   settable   0
 *
 *
 * Its syntax is INTEGER (based on perltype INTEGER)
 * The net-snmp type is ASN_INTEGER. The C type decl is long (long)
 */
/**
 * Extract the current value of the sesTxPkts data.
 *
 * Set a value using the data context for the row.
 *
 * @param rowreq_ctx
 *        Pointer to the row request context.
 * @param sesTxPkts_val_ptr
 *        Pointer to storage for a long variable
 *
 * @retval MFD_SUCCESS         : success
 * @retval MFD_SKIP            : skip this node (no value for now)
 * @retval MFD_ERROR           : Any other error
 */
int
sesTxPkts_get( sessionTable_rowreq_ctx *rowreq_ctx, u_long * sesTxPkts_val_ptr )
{
   /** we should have a non-NULL pointer */
   netsnmp_assert( NULL != sesTxPkts_val_ptr );


    DEBUGMSGTL(("verbose:sessionTable:sesTxPkts_get","called\n"));

    netsnmp_assert(NULL != rowreq_ctx);

		*sesTxPkts_val_ptr = rowreq_ctx->data->tx_pkts;

    return MFD_SUCCESS;
} /* sesTxPkts_get */

/** @} */
