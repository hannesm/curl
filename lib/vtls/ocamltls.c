
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
  /* see urldata.h for connectdata et al struct definition */
  /*  conn->recv[sockindex] = ocamltls_recv;
      conn->send[sockindex] = ocamltls_send;
  rsa_free(&conn->ssl[sockindex].rsa);
  x509_crt_free(&conn->ssl[sockindex].clicert);
  x509_crt_free(&conn->ssl[sockindex].cacert);
  x509_crl_free(&conn->ssl[sockindex].crl);
  ssl_free(&conn->ssl[sockindex].ssl);

  struct ssl_connect_data* connssl = &conn->ssl[sockindex];
  ssl_session *our_ssl_sessionid = &conn->ssl[sockindex].ssn ;
  ret = ssl_write(&conn->ssl[sockindex].ssl,
                  (unsigned char *)mem, len);

  */
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
