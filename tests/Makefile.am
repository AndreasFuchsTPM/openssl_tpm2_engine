TESTS = fail_connect.sh
TESTS += start_sw_tpm.sh
if HAVE_IBM_TSS
TESTS += check_tpm_directory.sh
endif
TESTS += check_curves.sh \
	create_tpm_key.sh \
	create_tpm_key_auth.sh \
	check_auth.sh \
	wrap_tpm_key.sh \
	check_wrap_auth.sh \
	check_old_keys.sh \
	check_der.sh \
	create_ecc.sh \
	create_nonopenssl_ecc.sh \
	wrap_ecc.sh \
	wrap_generic_ecc.sh \
	wrap_pkcs12.sh \
	derive_ecc.sh \
	create_non_tpm_keys.sh \
	da_check.sh \
	test_nv_key.sh \
	check_enhanced_auth.sh \
	check_counter_timer.sh \
	check_importable.sh \
	check_rsa_oaep_pss.sh \
	restricted_parent.sh \
	seal_unseal.sh \
	stop_sw_tpm.sh

fail_connect.sh: tpm_server_found

tpm_server_found:
	@if [ -z "$(testtpm)" ]; then echo "ERROR: Can't run tests, no tpm server is found"; exit 1; fi

if USE_SWTPM
AM_TESTS_ENVIRONMENT = TPM_INTERFACE_TYPE=swtpm; export TPM_INTERFACE_TYPE; \
	srcdir=$(abs_srcdir); export srcdir; \
	OPENSSL_CONF=$(abs_srcdir)/openssl.cnf; export OPENSSL_CONF; \
	TPMSERVER=$(TPMSERVER); export TPMSERVER; \
	TSSTYPE=@TSSTYPE@; export TSSTYPE; \
	SWTPM=$(SWTPM); export SWTPM; \
	SWTPM_IOCTL=$(SWTPM_IOCTL); export SWTPM_IOCTL; \
    TPM2TOOLS_TCTI=swtpm; export TPM2TOOLS_TCTI;
else
AM_TESTS_ENVIRONMENT = TPM_INTERFACE_TYPE=socsim; export TPM_INTERFACE_TYPE; \
	srcdir=$(abs_srcdir); export srcdir; \
	OPENSSL_CONF=$(abs_srcdir)/openssl.cnf; export OPENSSL_CONF; \
	TPMSERVER=$(TPMSERVER); export TPMSERVER; \
	TSSTYPE=@TSSTYPE@; export TSSTYPE; \
	SWTPM=$(SWTPM); export SWTPM; \
	SWTPM_IOCTL=$(SWTPM_IOCTL); export SWTPM_IOCTL; \
    TPM2TOOLS_TCTI=mssim; export TPM2TOOLS_TCTI;
endif

TEST_EXTENSIONS = .sh

CLEANFILES = key*.tpm key*.pub key*.priv tmp.* NVChip h*.bin key*.der seal.*
clean-local:
	rm -fr testdir
