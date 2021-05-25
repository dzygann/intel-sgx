#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include "untrusted/p11Sgx.h"
#include "untrusted/P11Provider.h"

using namespace std;

const CK_BBOOL ON_TOKEN = CK_TRUE;
const CK_BBOOL IN_SESSION = CK_FALSE;

// CKA_PRIVATE
const CK_BBOOL IS_PRIVATE = CK_TRUE;
const CK_BBOOL IS_PUBLIC = CK_FALSE;


CK_SLOT_ID m_initializedTokenSlotID;
CK_SESSION_HANDLE hSession;
CK_OBJECT_HANDLE hPuk = CK_INVALID_HANDLE;
CK_OBJECT_HANDLE hPrk = CK_INVALID_HANDLE;

CK_BYTE signature[256];
CK_ULONG ulSignatureLen = 0;


void evaluateReturnValue(CK_RV rv){
	if (CKR_OK != rv) {
		puts("NOT OK");
	}

	if (rv == CKR_CRYPTOKI_NOT_INITIALIZED) {
		puts("CKR_CRYPTOKI_NOT_INITIALIZED");
	}
	if (rv == CKR_SESSION_HANDLE_INVALID) {
		puts("CKR_SESSION_HANDLE_INVALID");
	}
	if (rv == CKR_ARGUMENTS_BAD) {
		puts("CKR_ARGUMENTS_BAD");
	}
	if (rv == CKR_DEVICE_MEMORY) {
		puts("CKR_DEVICE_MEMORY");
	}
	if (rv == CKR_GENERAL_ERROR) {
		puts("CKR_GENERAL_ERROR");
	}
	if (rv == CKR_SESSION_READ_ONLY_EXISTS) {
		puts("CKR_SESSION_READ_ONLY_EXISTS");
	}
	if (rv == CKR_OPERATION_NOT_INITIALIZED) {
		puts("CKR_OPERATION_NOT_INITIALIZED");
	}
	if (rv == CKR_USER_TYPE_INVALID) {
		puts("CKR_USER_TYPE_INVALID");
	}
	if (rv == CKR_USER_TOO_MANY_TYPES) {
		puts("CKR_USER_TOO_MANY_TYPES");
	}
	if (rv == CKR_USER_ANOTHER_ALREADY_LOGGED_IN) {
		puts("CKR_USER_ANOTHER_ALREADY_LOGGED_IN");
	}
	if (rv == CKR_USER_NOT_LOGGED_IN) {
		puts("CKR_USER_NOT_LOGGED_IN");
	}
	if (rv == CKR_USER_PIN_NOT_INITIALIZED) {
		puts("CKR_USER_PIN_NOT_INITIALIZED");
	}
	if (rv == CKR_USER_ALREADY_LOGGED_IN) {
		puts("CKR_USER_ALREADY_LOGGED_IN");
	}
	if(rv == CKR_SESSION_PARALLEL_NOT_SUPPORTED){
		puts("CKR_SESSION_PARALLEL_NOT_SUPPORTED");
	}
	if(rv == CKR_SESSION_HANDLE_INVALID){
		puts("CKR_SESSION_HANDLE_INVALID");
	}
	if (rv == CKR_FUNCTION_FAILED) {
		puts("CKR_FUNCTION_FAILED");
	}
	if (rv == CKR_CANCEL) {
		puts("CKR_CANCEL");
	}
	if (rv == CKR_HOST_MEMORY) {
		puts("CKR_HOST_MEMORY");
	}
	if (rv == CKR_SLOT_ID_INVALID) {
		puts("CKR_SLOT_ID_INVALID");
	}
	if (rv == CKR_NO_EVENT) {
		puts("CKR_NO_EVENT");
	}
	if (rv == CKR_NEED_TO_CREATE_THREADS) {
		puts("CKR_NEED_TO_CREATE_THREADS");
	}
	if (rv == CKR_CANT_LOCK) {
		puts("CKR_CANT_LOCK");
	}
	if (rv == CKR_ATTRIBUTE_READ_ONLY) {
		puts("CKR_ATTRIBUTE_READ_ONLY");
	}
	if (rv == CKR_ATTRIBUTE_SENSITIVE) {
		puts("CKR_ATTRIBUTE_SENSITIVE");
	}
	if (rv == CKR_ATTRIBUTE_TYPE_INVALID) {
		puts("CKR_ATTRIBUTE_TYPE_INVALID");
	}
	if (rv == CKR_ATTRIBUTE_VALUE_INVALID) {
		puts("CKR_ATTRIBUTE_VALUE_INVALID");
	}
	if (rv == CKR_ACTION_PROHIBITED) {
		puts("CKR_ACTION_PROHIBITED");
	}
	if (rv == CKR_DATA_INVALID) {
		puts("CKR_DATA_INVALID");
	}
	if (rv == CKR_DATA_LEN_RANGE) {
		puts("CKR_DATA_LEN_RANGE");
	}
	if (rv == CKR_DEVICE_ERROR) {
		puts("CKR_DEVICE_ERROR");
	}
	if (rv == CKR_DEVICE_REMOVED) {
		puts("CKR_DEVICE_REMOVED");
	}
	if (rv == CKR_ENCRYPTED_DATA_INVALID) {
		puts("CKR_ENCRYPTED_DATA_INVALID");
	}
	if (rv == CKR_ENCRYPTED_DATA_LEN_RANGE) {
		puts("CKR_ENCRYPTED_DATA_LEN_RANGE");
	}
	if (rv == CKR_FUNCTION_CANCELED) {
		puts("CKR_FUNCTION_CANCELED");
	}
	if (rv == CKR_FUNCTION_NOT_PARALLEL) {
		puts("CKR_FUNCTION_NOT_PARALLEL");
	}
	if (rv == CKR_FUNCTION_NOT_SUPPORTED) {
		puts("CKR_FUNCTION_NOT_SUPPORTED");
	}
	if (rv == CKR_KEY_HANDLE_INVALID) {
		puts("CKR_KEY_HANDLE_INVALID");
	}
	if (rv == CKR_KEY_SIZE_RANGE) {
		puts("CKR_KEY_SIZE_RANGE");
	}
	if (rv == CKR_KEY_TYPE_INCONSISTENT) {
		puts("CKR_KEY_TYPE_INCONSISTENT");
	}
	if (rv == CKR_KEY_NOT_NEEDED) {
		puts("CKR_KEY_NOT_NEEDED");
	}
	if (rv == CKR_KEY_CHANGED) {
		puts("CKR_KEY_CHANGED");
	}
	if (rv == CKR_KEY_NEEDED) {
		puts("CKR_KEY_NEEDED");
	}
	if (rv == CKR_KEY_INDIGESTIBLE) {
		puts("CKR_KEY_INDIGESTIBLE");
	}
	if (rv == CKR_KEY_FUNCTION_NOT_PERMITTED) {
		puts("CKR_KEY_FUNCTION_NOT_PERMITTED");
	}
	if (rv == CKR_KEY_NOT_WRAPPABLE) {
		puts("CKR_KEY_NOT_WRAPPABLE");
	}
	if (rv == CKR_KEY_UNEXTRACTABLE) {
		puts("CKR_KEY_UNEXTRACTABLE");
	}
	if (rv == CKR_MECHANISM_INVALID) {
		puts("CKR_MECHANISM_INVALID");
	}
	if (rv == CKR_MECHANISM_PARAM_INVALID) {
		puts("CKR_MECHANISM_PARAM_INVALID");
	}
	if (rv == CKR_OBJECT_HANDLE_INVALID) {
		puts("CKR_OBJECT_HANDLE_INVALID");
	}
	if (rv == CKR_OPERATION_ACTIVE) {
		puts("CKR_OPERATION_ACTIVE");
	}
	if (rv == CKR_OPERATION_NOT_INITIALIZED) {
		puts("CKR_OPERATION_NOT_INITIALIZED");
	}
	if (rv == CKR_PIN_INCORRECT) {
		puts("CKR_PIN_INCORRECT");
	}
	if (rv == CKR_PIN_INVALID) {
		puts("CKR_PIN_INVALID");
	}
	if (rv == CKR_PIN_LEN_RANGE) {
		puts("CKR_PIN_LEN_RANGE");
	}
	if (rv == CKR_PIN_EXPIRED) {
		puts("CKR_PIN_EXPIRED");
	}
	if (rv == CKR_PIN_LOCKED) {
		puts("CKR_PIN_LOCKED");
	}
	if (rv == CKR_SESSION_CLOSED) {
		puts("CKR_SESSION_CLOSED");
	}
	if (rv == CKR_SESSION_COUNT) {
		puts("CKR_SESSION_COUNT");
	}
	if (rv == CKR_SESSION_HANDLE_INVALID) {
		puts("CKR_SESSION_HANDLE_INVALID");
	}
	if (rv == CKR_SESSION_PARALLEL_NOT_SUPPORTED) {
		puts("CKR_SESSION_PARALLEL_NOT_SUPPORTED");
	}
	if (rv == CKR_SESSION_READ_ONLY) {
		puts("CKR_SESSION_READ_ONLY");
	}
	if (rv == CKR_SESSION_EXISTS) {
		puts("CKR_SESSION_EXISTS");
	}
	if (rv == CKR_SESSION_READ_ONLY_EXISTS) {
		puts("CKR_SESSION_READ_ONLY_EXISTS");
	}
	if (rv == CKR_SESSION_READ_WRITE_SO_EXISTS) {
		puts("CKR_SESSION_READ_WRITE_SO_EXISTS");
	}
	if (rv == CKR_SIGNATURE_INVALID) {
		puts("CKR_SIGNATURE_INVALID");
	}
	if (rv == CKR_SIGNATURE_LEN_RANGE) {
		puts("CKR_SIGNATURE_LEN_RANGE");
	}
	if (rv == CKR_TEMPLATE_INCOMPLETE) {
		puts("CKR_TEMPLATE_INCOMPLETE");
	}
	if (rv == CKR_TEMPLATE_INCONSISTENT) {
		puts("CKR_TEMPLATE_INCONSISTENT");
	}
	if (rv == CKR_TOKEN_NOT_PRESENT) {
		puts("CKR_TOKEN_NOT_PRESENT");
	}
	if (rv == CKR_TOKEN_NOT_RECOGNIZED) {
		puts("CKR_TOKEN_NOT_RECOGNIZED");
	}
	if (rv == CKR_TOKEN_WRITE_PROTECTED) {
		puts("CKR_TOKEN_WRITE_PROTECTED");
	}
	if (rv == CKR_UNWRAPPING_KEY_HANDLE_INVALID) {
		puts("CKR_UNWRAPPING_KEY_HANDLE_INVALID");
	}
	if (rv == CKR_UNWRAPPING_KEY_SIZE_RANGE) {
		puts("CKR_UNWRAPPING_KEY_SIZE_RANGE");
	}
	if (rv == CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT) {
		puts("CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT");
	}
	if (rv == CKR_USER_ALREADY_LOGGED_IN) {
		puts("CKR_USER_ALREADY_LOGGED_IN");
	}
	if (rv == CKR_USER_NOT_LOGGED_IN) {
		puts("CKR_USER_NOT_LOGGED_IN");
	}
	if (rv == CKR_USER_PIN_NOT_INITIALIZED) {
		puts("CKR_USER_PIN_NOT_INITIALIZED");
	}
	if (rv == CKR_USER_TYPE_INVALID) {
		puts("CKR_USER_TYPE_INVALID");
	}
	if (rv == CKR_USER_ANOTHER_ALREADY_LOGGED_IN) {
		puts("CKR_USER_ANOTHER_ALREADY_LOGGED_IN");
	}
	if (rv == CKR_USER_TOO_MANY_TYPES) {
		puts("CKR_USER_TOO_MANY_TYPES");
	}
	if (rv == CKR_WRAPPED_KEY_INVALID) {
		puts("CKR_WRAPPED_KEY_INVALID");
	}
	if (rv == CKR_WRAPPED_KEY_LEN_RANGE) {
		puts("CKR_WRAPPED_KEY_LEN_RANGE");
	}
	if (rv == CKR_WRAPPING_KEY_HANDLE_INVALID) {
		puts("CKR_WRAPPING_KEY_HANDLE_INVALID");
	}
	if (rv == CKR_WRAPPING_KEY_SIZE_RANGE) {
		puts("CKR_WRAPPING_KEY_SIZE_RANGE");
	}
	if (rv == CKR_WRAPPING_KEY_TYPE_INCONSISTENT) {
		puts("CKR_WRAPPING_KEY_TYPE_INCONSISTENT");
	}
	if (rv == CKR_RANDOM_SEED_NOT_SUPPORTED) {
		puts("CKR_RANDOM_SEED_NOT_SUPPORTED");
	}
	if (rv == CKR_RANDOM_NO_RNG) {
		puts("CKR_RANDOM_NO_RNG");
	}
	if (rv == CKR_DOMAIN_PARAMS_INVALID) {
		puts("CKR_DOMAIN_PARAMS_INVALID");
	}
	if (rv == CKR_CURVE_NOT_SUPPORTED) {
		puts("CKR_CURVE_NOT_SUPPORTED");
	}
	if (rv == CKR_BUFFER_TOO_SMALL) {
		puts("CKR_BUFFER_TOO_SMALL");
	}


//	CKR_SAVED_STATE_INVALID
//	CKR_INFORMATION_SENSITIVE
//	CKR_STATE_UNSAVEABLE
//	CKR_CRYPTOKI_NOT_INITIALIZED
//	CKR_CRYPTOKI_ALREADY_INITIALIZED
//	CKR_MUTEX_BAD
//	CKR_MUTEX_NOT_LOCKED
//
//	CKR_NEW_PIN_MODE
//	CKR_NEXT_OTP
//
//	CKR_EXCEEDED_MAX_ITERATIONS
//	CKR_FIPS_SELF_TEST_FAILED
//	CKR_LIBRARY_LOAD_FAILED
//	CKR_PIN_TOO_WEAK
//	CKR_PUBLIC_KEY_INVALID
//
//	CKR_FUNCTION_REJECTED
//
//	CKR_VENDOR_DEFINED

	if (rv == CKR_OK) {
		puts("CKR_OK");
	}
}

CK_RV generateEC(const char *curve, CK_SESSION_HANDLE hSession,
		CK_BBOOL bTokenPuk, CK_BBOOL bPrivatePuk, CK_BBOOL bTokenPrk,
		CK_BBOOL bPrivatePrk) {

	CK_MECHANISM mechanism = { CKM_EC_KEY_PAIR_GEN, NULL_PTR, 0 };
	CK_KEY_TYPE keyType = CKK_EC;
	CK_BYTE oidP256[] = { 0x06, 0x08, 0x2A, 0x86, 0x48, 0xCE, 0x3D, 0x03, 0x01,
			0x07 };
	CK_BYTE oidP384[] = { 0x06, 0x05, 0x2B, 0x81, 0x04, 0x00, 0x22 };
	CK_BYTE oidP521[] = { 0x06, 0x05, 0x2B, 0x81, 0x04, 0x00, 0x23 };
	CK_BYTE label[] = { 0x12, 0x34 }; // dummy
	CK_BYTE id[] = { 123 }; // dummy
	CK_BBOOL bFalse = CK_FALSE;
	CK_BBOOL bTrue = CK_TRUE;

	CK_ATTRIBUTE pukAttribs[] = {
			{ CKA_EC_PARAMS, NULL, 0 },
			{ CKA_LABEL, &label[0], sizeof(label) },
			{ CKA_ID, &id[0], sizeof(id) },
			{ CKA_KEY_TYPE, &keyType, sizeof(keyType) },
			{ CKA_VERIFY, &bTrue, sizeof(bTrue) },
			{ CKA_ENCRYPT, &bFalse, sizeof(bFalse) },
			{ CKA_WRAP, &bFalse, sizeof(bFalse) },
			{ CKA_TOKEN, &bTokenPuk, sizeof(bTokenPuk) },
			{ CKA_PRIVATE, &bPrivatePuk, sizeof(bPrivatePuk) } };

	CK_ATTRIBUTE prkAttribs[] = {
			{ CKA_LABEL, &label[0], sizeof(label) },
			{ CKA_ID, &id[0], sizeof(id) },
			{ CKA_KEY_TYPE, &keyType, sizeof(keyType) },
			{ CKA_SIGN, &bTrue, sizeof(bTrue) },
			{ CKA_DECRYPT, &bFalse, sizeof(bFalse) },
			{ CKA_UNWRAP, &bFalse, sizeof(bFalse) },
			{ CKA_SENSITIVE, &bTrue, sizeof(bTrue) },
			{ CKA_TOKEN, &bTokenPrk, sizeof(bTokenPrk) },
			{ CKA_PRIVATE, &bPrivatePrk, sizeof(bPrivatePrk) },
			{ CKA_EXTRACTABLE, &bFalse,	sizeof(bFalse) } };

	/* Select the curve */
	if (strcmp(curve, "P-256") == 0) {
		pukAttribs[0].pValue = oidP256;
		pukAttribs[0].ulValueLen = sizeof(oidP256);
	} else if (strcmp(curve, "P-384") == 0) {
		pukAttribs[0].pValue = oidP384;
		pukAttribs[0].ulValueLen = sizeof(oidP384);
	} else if (strcmp(curve, "P-521") == 0) {
		pukAttribs[0].pValue = oidP521;
		pukAttribs[0].ulValueLen = sizeof(oidP521);
	} else {
		return CKR_GENERAL_ERROR;
	}

	return C_GenerateKeyPair(hSession, &mechanism, pukAttribs,
			sizeof(pukAttribs) / sizeof(CK_ATTRIBUTE), prkAttribs,
			sizeof(prkAttribs) / sizeof(CK_ATTRIBUTE), &hPuk, &hPrk);
}



//INIT
void initialize(CK_RV &rv) {
	puts("Init");
	rv = C_Initialize(NULL_PTR);
	evaluateReturnValue(rv);
}

//Open Session
void openSession(CK_RV &rv) {
	puts("Open Session");
	rv = C_OpenSession(m_initializedTokenSlotID,
			CKF_SERIAL_SESSION | CKF_RW_SESSION, NULL_PTR, NULL_PTR, &hSession);
	evaluateReturnValue(rv);
}

//Get Slot List
void getSlotList(CK_RV &rv) {
	puts("Get Slot List to get Slot Size");
	CK_ULONG nrOfSlots = 0;

	rv = C_GetSlotList(CK_FALSE, NULL_PTR, &nrOfSlots);
	evaluateReturnValue(rv);
	cout << "NrOfSlots: " << printf("%lu", nrOfSlots) << endl;

	puts("Get Slot List to get Slot IDs");
	vector<CK_SLOT_ID> slotIDs(nrOfSlots);
	rv = C_GetSlotList(CK_TRUE, &slotIDs.front(), &nrOfSlots);
	evaluateReturnValue(rv);
	cout << "SlotID[0]: " << slotIDs.front() << endl;

	puts("Init Token");
	CK_TOKEN_INFO tokenInfo;
	rv = C_GetTokenInfo(slotIDs.front(), &tokenInfo);
	evaluateReturnValue(rv);
	cout << "token info: " << tokenInfo.label << endl;
	if (tokenInfo.flags & CKF_TOKEN_INITIALIZED) {
		m_initializedTokenSlotID = slotIDs.front();
	}
	cout << "m_initializedTokenSlotID: " << m_initializedTokenSlotID << endl;

}


//Generate Elliptic Curve
void generateEC(CK_RV &rv) {
	puts("Generate EC");

	rv = generateEC("P-256", hSession, IN_SESSION, IS_PUBLIC, IN_SESSION,
				IS_PUBLIC);
	evaluateReturnValue(rv);
	cout << "hPuk: " << printf("%lu", hPuk) << endl;
	cout << "hPrk: " << printf("%lu", hPrk) << endl;
}

//Sign
void sign(CK_RV &rv) {
	puts("SignInit");
	CK_MECHANISM mechanism = { CKM_ECDSA, NULL_PTR, NULL_PTR };
	CK_BYTE data[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
			0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F };


	rv = C_SignInit(hSession, &mechanism, hPrk);
	evaluateReturnValue(rv);

	puts("Sign");
	ulSignatureLen = sizeof(signature);
	rv = C_Sign(hSession, data, sizeof(data), signature, &ulSignatureLen);
	evaluateReturnValue(rv);
	//string sName(reinterpret_cast<char*>(signature));
	string s( reinterpret_cast<const char*>(signature));
	cout << "Sign Signature: " << +signature << endl;
}

//verify
void verify(CK_RV &rv) {
	puts("VerifyInit");
	CK_MECHANISM mechanism = { CKM_ECDSA, NULL_PTR, NULL_PTR };
	CK_BYTE data[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
			0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F };

	rv = C_VerifyInit(hSession, &mechanism, hPuk);
	evaluateReturnValue(rv);

	puts("Verify");
	//ulSignatureLen = sizeof(signature);
	rv = C_Verify(hSession, data, sizeof(data), signature, ulSignatureLen);
	evaluateReturnValue(rv);
}

//verify
void verify(CK_RV &rv, char* digestHash, char* seckey) {
	puts("VerifyInit");
	CK_MECHANISM mechanism = { CKM_ECDSA, NULL_PTR, NULL_PTR };
	CK_BYTE data[] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
			0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0F };


	rv = C_VerifyInit(hSession, &mechanism, hPuk);
	evaluateReturnValue(rv);

	puts("Verify");
	ulSignatureLen = sizeof(signature);
	rv = C_Verify(hSession, data, sizeof(data), signature, ulSignatureLen);
	evaluateReturnValue(rv);
}






int main(int argc, char **argv) {
	CK_RV rv;

	for (int i = 0; i < argc; ++i)
	        cout << "i: " << i << " " << argv[i] << "\n";

	if(argc > 1 && strcmp(argv[1], "initialize") == 0) {
		initialize(rv);
	}

	if(argc > 1 && strcmp(argv[1], "getSlotList") == 0) {
		initialize(rv);
		getSlotList(rv);
	}

	if(argc > 1 && strcmp(argv[1], "openSession") == 0) {
		initialize(rv);
		getSlotList(rv);
		openSession(rv);
	}

	if(argc > 1 && strcmp(argv[1], "generateEC") == 0) {
		initialize(rv);
		getSlotList(rv);
		openSession(rv);
		generateEC(rv);
	}

	if(argc > 1 && strcmp(argv[1], "sign") == 0) {
		initialize(rv);
		getSlotList(rv);
		openSession(rv);
		generateEC(rv);
		sign(rv);
	}
	if(argc > 1 && strcmp(argv[1], "verify") == 0) {
		initialize(rv);
		getSlotList(rv);
		openSession(rv);
		generateEC(rv);
		sign(rv);
		verify(rv);
	}
	if(argc > 3 && strcmp(argv[1], "verify") == 0) {
		initialize(rv);
		getSlotList(rv);
		openSession(rv);
		// digestHash, seckey
		verify(rv, argv[2], argv[3]);
	}



	return 0;
}
