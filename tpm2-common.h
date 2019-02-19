#ifndef _TPM2_COMMON_H
#define _TPM2_COMMON_H

#define	T2_AES_KEY_BITS		128
#define T2_AES_KEY_BYTES	(T2_AES_KEY_BITS/8)

struct policy_command {
	TPM_CC code;
	INT32 size;
	BYTE *policy;
};

void tpm2_error(TPM_RC rc, const char *reason);
TPM_RC tpm2_load_srk(TSS_CONTEXT *tssContext, TPM_HANDLE *h, const char *auth, TPM2B_PUBLIC *pub, TPM_HANDLE handle, int version);
void tpm2_flush_handle(TSS_CONTEXT *tssContext, TPM_HANDLE h);
EVP_PKEY *tpm2_to_openssl_public(TPMT_PUBLIC *pub);
void tpm2_flush_srk(TSS_CONTEXT *tssContext, TPM_HANDLE hSRK);
TPM_RC tpm2_get_session_handle(TSS_CONTEXT *tssContext, TPM_HANDLE *handle,
			       TPM_HANDLE salt_key, TPM_SE sessionType,
			       TPM_ALG_ID name_alg);
TPM_RC tpm2_init_session(TSS_CONTEXT *tssContext, TPM_HANDLE handle,
			 int num_commands, struct policy_command *commands,
			 TPM_ALG_ID name_alg);
TPM_RC tpm2_get_bound_handle(TSS_CONTEXT *tssContext, TPM_HANDLE *handle,
			     TPM_HANDLE bind, const char *auth);
TPMI_ECC_CURVE tpm2_curve_name_to_TPMI(const char *name);
int tpm2_curve_name_to_nid(TPMI_ECC_CURVE curve);
TPMI_ECC_CURVE tpm2_nid_to_curve_name(int nid);
TPMI_ECC_CURVE tpm2_get_curve_name(const EC_GROUP *g);
const char *tpm2_curve_name_to_text(TPMI_ECC_CURVE curve);
const char *tpm2_set_unique_tssdir(void);
TPM_RC tpm2_create(TSS_CONTEXT **tsscp, const char *dir);
TPM_RC tpm2_readpublic(TSS_CONTEXT *tssContext, TPM_HANDLE handle,
		       TPMT_PUBLIC *pub);
void tpm2_rm_tssdir(const char *dir);
void tpm2_rm_keyfile(const char *dir, TPM_HANDLE key);
int tpm2_get_public_point(TPM2B_ECC_POINT *tpmpt, const EC_GROUP *group,
			  const EC_POINT *pt);
#endif
