/***************************************************************************
 *                                  _   _ ____  _
 *  Project                     ___| | | |  _ \| |
 *                             / __| | | | |_) | |
 *                            | (__| |_| |  _ <| |___
 *                             \___|\___/|_| \_\_____|
 *
 * Copyright (C) 2011, Daniel Stenberg, <daniel@haxx.se>, et al.
 *
 * This software is licensed as described in the file COPYING, which
 * you should have received as part of this distribution. The terms
 * are also available at http://curl.haxx.se/docs/copyright.html.
 *
 * You may opt to use, copy, modify, merge, publish, distribute and/or sell
 * copies of the Software, and permit persons to whom the Software is
 * furnished to do so, under the terms of the COPYING file.
 *
 * This software is distributed on an "AS IS" basis, WITHOUT WARRANTY OF ANY
 * KIND, either express or implied.
 *
 ***************************************************************************/

#include "gssapi.h"

OM_uint32 Curl_gss_init_sec_context(
    OM_uint32 * minor_status,
    gss_ctx_id_t * context,
    gss_name_t target_name,
    gss_channel_bindings_t input_chan_bindings,
    gss_buffer_t input_token,
    gss_buffer_t output_token,
    OM_uint32 * ret_flags)
{
  return gss_init_sec_context(minor_status,
                              GSS_C_NO_CREDENTIAL, /* cred_handle */
                              context,
                              target_name,
                              GSS_C_NO_OID, /* mech_type */
                              /* req_flags */
                              GSS_C_MUTUAL_FLAG | GSS_C_REPLAY_FLAG,
                              0, /* time_req */
                              input_chan_bindings,
                              input_token,
                              NULL, /* actual_mech_type */
                              output_token,
                              ret_flags,
                              NULL /* time_rec */);
}