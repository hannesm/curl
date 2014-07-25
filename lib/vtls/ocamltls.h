#ifndef HEADER_CURL_OCAMLTLS_H
#define HEADER_CURL_OCAMLTLS_H

#ifdef USE_OCAMLTLS

int ocamltls_init (void);

CURLcode ocamltls_connect(struct connectdata *conn, int sockindex);

CURLcode ocamltls_connect_nonblocking(struct connectdata *conn,
                                           int sockindex,
                                           bool *done);

void ocamltls_close_all(struct SessionHandle *data);

void ocamltls_close(struct connectdata *conn, int sockindex);

void ocamltls_session_free(void *ptr);
size_t ocamltls_version(char *buffer, size_t size);

#define curlssl_init ocamltls_init
#define curlssl_cleanup ocamltls_cleanup
#define curlssl_connect ocamltls_connect
#define curlssl_connect_nonblocking ocamltls_connect_nonblocking
#define curlssl_session_free ocamltls_free
#define curlssl_close_all ocamltls_close_all
#define curlssl_close ocamltls_close
#define curlssl_shutdown(x, y) 0
#define curlssl_set_engine(x, y) (x=x, y=y, CURLE_NOT_BUILT_IN)
#define curlssl_set_engine_default(x) (x=x, CURLE_NOT_BUILT_IN)
#define curlssl_engines_list(x) (x=x, (struct curl_slist *)NULL)
#define curlssl_version ocamltls_version
#define curlssl_check_cxn(x) (x=x, -1)
#define curlssl_data_pending(x, y) (x=x, y=y, 0)


#endif /* USE_OCAMLTLS */
#endif /* HEADER_CURL_OCAMLTLS_H */
