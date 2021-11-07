/******************************************************************************
 * Copyright (C) 2018-2021 aitos.io
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "boatconfig.h"
#include "boatiotsdk.h"
#include <time.h>

const BCHAR * chainmaker_user_key = "-----BEGIN EC PRIVATE KEY-----\n"
									"MHcCAQEEIKK+XvZxuruLLZROu/kcL0DkTyru3B3YpRovEpjoufA1oAoGCCqGSM49\n"
									"AwEHoUQDQgAEr4tYkplYDG56ZHngTHV16MYfIp7cThIvotDdzY1UxNDCWRf+9FdX\n"
									"oLXO+LU8fJmKEL3C9wcYe2CwuxxnZnuaJA==\n"
									"-----END EC PRIVATE KEY-----\n";

const BCHAR * chainmaker_user_cert ="-----BEGIN CERTIFICATE-----\n"
									"MIICaTCCAg6gAwIBAgIDCQLCMAoGCCqGSM49BAMCMIGKMQswCQYDVQQGEwJDTjEQ\n"
									"MA4GA1UECBMHQmVpamluZzEQMA4GA1UEBxMHQmVpamluZzEfMB0GA1UEChMWd3gt\n"
									"b3JnMS5jaGFpbm1ha2VyLm9yZzESMBAGA1UECxMJcm9vdC1jZXJ0MSIwIAYDVQQD\n"
									"ExljYS53eC1vcmcxLmNoYWlubWFrZXIub3JnMB4XDTIxMTEwNTA3MDQwNFoXDTI2\n"
									"MTEwNDA3MDQwNFowgZExCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdCZWlqaW5nMRAw\n"
									"DgYDVQQHEwdCZWlqaW5nMR8wHQYDVQQKExZ3eC1vcmcxLmNoYWlubWFrZXIub3Jn\n"
									"MQ8wDQYDVQQLEwZjbGllbnQxLDAqBgNVBAMTI2NsaWVudDEuc2lnbi53eC1vcmcx\n"
									"LmNoYWlubWFrZXIub3JnMFkwEwYHKoZIzj0CAQYIKoZIzj0DAQcDQgAEr4tYkplY\n"
									"DG56ZHngTHV16MYfIp7cThIvotDdzY1UxNDCWRf+9FdXoLXO+LU8fJmKEL3C9wcY\n"
									"e2CwuxxnZnuaJKNaMFgwKQYDVR0OBCIEII98SnKFINcwDJPKFO5j0Lg74NUEGB7A\n"
									"OB0rBrj+255iMCsGA1UdIwQkMCKAIC6CzrupVs0JiDU7tsAhWVOWWQqJnQl3NMFY\n"
									"ISPFx9atMAoGCCqGSM49BAMCA0kAMEYCIQD9G8pXsRig7CWUXysmipY2S+QcmXyS\n"
									"a1azgQ44SZFRowIhAOSqB0T6fjVYc6owMKfUtUJpEC1XSO/tlHDD0NpdLCWk\n"
									"-----END CERTIFICATE-----\n";



const BCHAR *chainmaker_org_tls_ca_cert =   "-----BEGIN CERTIFICATE-----\n"
											"MIICaDCCAg2gAwIBAgIDASOLMAoGCCqGSM49BAMCMIGKMQswCQYDVQQGEwJDTjEQ\n"
											"MA4GA1UECBMHQmVpamluZzEQMA4GA1UEBxMHQmVpamluZzEfMB0GA1UEChMWd3gt\n"
											"b3JnMS5jaGFpbm1ha2VyLm9yZzESMBAGA1UECxMJcm9vdC1jZXJ0MSIwIAYDVQQD\n"
											"ExljYS53eC1vcmcxLmNoYWlubWFrZXIub3JnMB4XDTIxMTEwNDE1MjYxOFoXDTI2\n"
											"MTEwMzE1MjYxOFowgZAxCzAJBgNVBAYTAkNOMRAwDgYDVQQIEwdCZWlqaW5nMRAw\n"
											"DgYDVQQHEwdCZWlqaW5nMR8wHQYDVQQKExZ3eC1vcmcxLmNoYWlubWFrZXIub3Jn\n"
											"MQ8wDQYDVQQLEwZjbGllbnQxKzApBgNVBAMTImNsaWVudDEudGxzLnd4LW9yZzEu\n"
											"Y2hhaW5tYWtlci5vcmcwWTATBgcqhkjOPQIBBggqhkjOPQMBBwNCAASnsMSX7Ext\n"
											"ve3k6iuic565OvEbyzqpZhmOJzSHyHAeQLoAaxaVrfdhKSKv+BTP+G4B9vtoiTv2\n"
											"ivkx+0fusbHCo1owWDApBgNVHQ4EIgQgTNoJ0i4SvDiXqMjvIT34OwlzhRUlRJEv\n"
											"DzJoWVVpimAwKwYDVR0jBCQwIoAgFXNa14VEFwAzhtccsY5AY9Mxt7qk6R5DFot6\n"
											"C1QeLzcwCgYIKoZIzj0EAwIDSQAwRgIhAJ71SLWBzKM7dw0SQ9T4UmzAfzTFBCqZ\n"
											"g8ss2+gWyqP9AiEAp2tcMOY4JPQcWT6sG0Q7zQdP8LQdmEqZrwZFubJUtSE=\n"
											"-----END CERTIFICATE-----\n";


BCHAR *chain_Id              = "chain1";
BCHAR *org_Id                = "wx-org1.chainmaker.org";
BCHAR *claim_contract_name   = "fact";
BCHAR *chainmaker_node_url   = "127.0.0.1:12301";
BCHAR *chainmaker_host_name  = "chainmaker.org";
BCHAR *invoke_metod          = "save";
BCHAR *query_metod           = "find_by_file_hash";   

BCHAR *key1 = "time";
BCHAR *key2 = "file_hash";
BCHAR *key3 = "file_name";

#define TIME_LEN 80
BCHAR str_value[90] = {"file_"};
BCHAR time_buf[TIME_LEN]  = {0};
BCHAR file_hash[33] = {0};

BoatHlchainmakerWallet *g_chaninmaker_wallet_ptr;
BoatHlchainmakerWalletConfig wallet_config = {0};

void get_time_string(char* time_buf)
{
	time_t rawtime;
	struct tm *info;

	time(&rawtime);
	info = localtime(&rawtime);
	strftime(time_buf, TIME_LEN, "%Y-%m-%d %H:%M:%S", info);	
	return;
} 

__BOATSTATIC BOAT_RESULT chainmakerWalletPrepare(void)
{
	BOAT_RESULT index;

	//set user private key context
	wallet_config.user_prikey_config.prikey_genMode = BOAT_WALLET_PRIKEY_GENMODE_EXTERNAL_INJECTION;
	wallet_config.user_prikey_config.prikey_type    = BOAT_WALLET_PRIKEY_TYPE_SECP256R1;
	wallet_config.user_prikey_config.prikey_format  = BOAT_WALLET_PRIKEY_FORMAT_PKCS;
	wallet_config.user_prikey_config.prikey_content.field_ptr = (BUINT8 *)chainmaker_user_key;
	wallet_config.user_prikey_config.prikey_content.field_len = strlen(chainmaker_user_key) + 1; 

	//set user cert context
	wallet_config.user_cert_content.length = strlen(chainmaker_user_cert);
	memcpy(wallet_config.user_cert_content.content, chainmaker_user_cert, wallet_config.user_cert_content.length);
	
	wallet_config.node_cfg.org_Id    = org_Id;
	wallet_config.node_cfg.chain_Id  = chain_Id;
	wallet_config.node_cfg.node_url  = chainmaker_node_url;
	wallet_config.node_cfg.host_name = chainmaker_host_name;
	wallet_config.node_cfg.claim_contract_name  = claim_contract_name;
	wallet_config.node_cfg.org_tls_ca_cert.length = strlen(chainmaker_org_tls_ca_cert);
	memcpy(wallet_config.node_cfg.org_tls_ca_cert.content, chainmaker_org_tls_ca_cert, wallet_config.node_cfg.org_tls_ca_cert.length);
		
	/* create chainmaker wallet */
	index = BoatWalletCreate(BOAT_PROTOCOL_CHAINMAKER, NULL, &wallet_config, sizeof(BoatHlchainmakerWalletConfig));
	if (index == BOAT_ERROR)
	{
		return BOAT_ERROR;
	}
	
	g_chaninmaker_wallet_ptr = BoatGetWalletByIndex(index);
	if (g_chaninmaker_wallet_ptr == NULL)
	{
		return BOAT_ERROR;
	}

	return BOAT_SUCCESS;
}

BoatTransactionPara get_invoke_para()
{
	//randrom generate
	BoatFieldMax16B  random_data;
	random_data.field_len = 16;
	BoatRandom(random_data.field, random_data.field_len, NULL);

	get_time_string(time_buf);
	array_to_str(random_data.field ,file_hash, 16);
	
	BoatTransactionPara transaction_para;
	transaction_para.n_parameters = 3;
	transaction_para.parameters = BoatMalloc(transaction_para.n_parameters * sizeof(BoatKeyValuePair));

	transaction_para.parameters[0].key   = key1;
	transaction_para.parameters[0].value = time_buf;
	transaction_para.parameters[1].key   = key2;
	transaction_para.parameters[1].value = file_hash;;
	transaction_para.parameters[2].key   = key3;
	transaction_para.parameters[2].value = strcat(str_value, time_buf);
	
	return transaction_para;
}

int main(int argc, char *argv[])
{
	BOAT_RESULT           result  = BOAT_SUCCESS;
	BoatHlchainmakerTx    tx_ptr;
	BoatTransactionPara   inovke_transaction_para;
	BoatTransactionPara   query_transaction_para;

	/* step-1: Boat SDK initialization */
    BoatIotSdkInit();

	/* step-2: prepare wallet */
	result = chainmakerWalletPrepare();
	if (result != BOAT_SUCCESS)
	{
		return -1;
	}

	/* step-3: Chainmaker transaction structure initialization */
	result = BoatHlChainmakerTxInit(g_chaninmaker_wallet_ptr, &tx_ptr);
	if (result != BOAT_SUCCESS)
	{
		return -1;
	}

	inovke_transaction_para = get_invoke_para();
	/* step-4: set transaction 'invoke' command */
	result = BoatHlchainmakerContractClaimInvoke(&tx_ptr, &inovke_transaction_para, invoke_metod); 
	if (result != BOAT_SUCCESS)
	{
		return -1;
	}

	/* step-5: wait seconds and 'query' the tansaction */
	BoatSleep(3);
	query_transaction_para.n_parameters = 1;
	query_transaction_para.parameters = BoatMalloc(sizeof(BoatKeyValuePair));
	query_transaction_para.parameters->key   = key2;
	query_transaction_para.parameters->value = file_hash;

	printf("query = %s\n", query_transaction_para.parameters->key);
	printf("query = %s\n", query_transaction_para.parameters->value);
	result = BoatHlchainmakerContractClaimQuery(&tx_ptr, &query_transaction_para, query_metod);
	if (result != BOAT_SUCCESS)
	{
		return -1;
	}

	/* step-6: chainmaker transaction structure Deinitialization */
	BoatHlchainmakerTxDeInit(&tx_ptr);
	
	/* step-7: Boat SDK Deinitialization */
    BoatIotSdkDeInit();
    
    return 0;
}

