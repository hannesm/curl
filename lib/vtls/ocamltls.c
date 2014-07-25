
#include "curl_setup.h"

#ifdef USE_POLARSSL

#include "ocamltls.h"

int ocamltls_init (void) {
  char *caml_argv[1] = { NULL };
  caml_startup(caml_argv);
  return 0;
}

size_t ocamltls_version (char *buffer, size_t size) {
  return snprintf(buffer, size, "PolarSSL/0.1.0");
}

void ocamltls_cleanup () {
}

void ocamltls_free (void *ptr) {
}

void ocamltls_close_all (struct SessionHandle *data) {
  (void)data;
}

void ocamltls_close (struct connectdata *conn, int sockindex) {
}

CURLcode ocamltls_connect_common (struct connectdata *conn, int sockindex) {
  /*  conn->recv[sockindex] = ocamltls_recv;
      conn->send[sockindex] = ocamltls_send; */
  return NULL
}

CURLcode ocamltls_connect_nonblocking (struct connectdata *conn,
                                       int sockindex,
                                       bool *done) {
  return ocamltls_connect_common(conn, sockindex);
}


CURLcode ocamltls_connect (struct connectdata *conn,
                           int sockindex) {
  return ocamltls_connect_common(conn, sockindex);
}
