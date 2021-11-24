/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: common/request.proto */

#ifndef PROTOBUF_C_common_2frequest_2eproto__INCLUDED
#define PROTOBUF_C_common_2frequest_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "contract.pb-c.h"
#include "member.pb-c.h"

typedef struct _Common__TxRequest Common__TxRequest;
typedef struct _Common__TxHeader Common__TxHeader;
typedef struct _Common__QueryPayload Common__QueryPayload;
typedef struct _Common__TransactPayload Common__TransactPayload;
typedef struct _Common__SystemContractPayload Common__SystemContractPayload;
typedef struct _Common__ContractMgmtPayload Common__ContractMgmtPayload;
typedef struct _Common__EndorsementEntry Common__EndorsementEntry;
typedef struct _Common__KeyValuePair Common__KeyValuePair;
typedef struct _Common__SubscribeContractEventPayload Common__SubscribeContractEventPayload;
typedef struct _Common__SubscribeBlockPayload Common__SubscribeBlockPayload;
typedef struct _Common__SubscribeTxPayload Common__SubscribeTxPayload;
typedef struct _Common__ArchiveBlockPayload Common__ArchiveBlockPayload;
typedef struct _Common__RestoreBlockPayload Common__RestoreBlockPayload;


/* --- enums --- */

/*
 * transaction type definition
 */
typedef enum _Common__TxType {
  /*
   * call a pre created user contract, tx included in block
   */
  COMMON__TX_TYPE__INVOKE_USER_CONTRACT = 0,
  /*
   * query a pre-created user contract, tx not included in block
   */
  COMMON__TX_TYPE__QUERY_USER_CONTRACT = 1,
  /*
   * create, upgrade, freeze, unfreeze, revoke a user contract, tx included in block
   */
  COMMON__TX_TYPE__MANAGE_USER_CONTRACT = 2,
  /*
   * call a system contract, tx included in block
   */
  COMMON__TX_TYPE__INVOKE_SYSTEM_CONTRACT = 7,
  /*
   * query a system contract, tx not included in block
   */
  COMMON__TX_TYPE__QUERY_SYSTEM_CONTRACT = 3,
  /*
   * update chain config, tx included in block
   */
  COMMON__TX_TYPE__UPDATE_CHAIN_CONFIG = 4,
  /*
   * subscribe block info, tx not included in block
   */
  COMMON__TX_TYPE__SUBSCRIBE_BLOCK_INFO = 5,
  /*
   * subscribe tx info, tx not included in block
   */
  COMMON__TX_TYPE__SUBSCRIBE_TX_INFO = 6,
  /*
   *subscribe contract event info, tx not included in block
   */
  COMMON__TX_TYPE__SUBSCRIBE_CONTRACT_EVENT_INFO = 8,
  /*
   * archive block
   */
  COMMON__TX_TYPE__ARCHIVE_FULL_BLOCK = 9,
  /*
   * restore archived block
   */
  COMMON__TX_TYPE__RESTORE_FULL_BLOCK = 10
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(COMMON__TX_TYPE)
} Common__TxType;

/* --- messages --- */

/*
 * transaction request proposed by user
 */
struct  _Common__TxRequest
{
  ProtobufCMessage base;
  /*
   * header of the request
   */
  Common__TxHeader *header;
  /*
   * payload of the request, can be unmarshalled according to tx_type in header
   */
  ProtobufCBinaryData payload;
  /*
   * signature of [header bytes || payload bytes]
   */
  ProtobufCBinaryData signature;
};
#define COMMON__TX_REQUEST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__tx_request__descriptor) \
    , NULL, {0,NULL}, {0,NULL} }


/*
 * header of the request
 */
struct  _Common__TxHeader
{
  ProtobufCMessage base;
  /*
   * blockchain identifier
   */
  char *chain_id;
  /*
   * sender identifier
   */
  Accesscontrol__SerializedMember *sender;
  /*
   * transaction type
   */
  Common__TxType tx_type;
  /*
   * transaction id set by sender, should be unique
   */
  char *tx_id;
  /*
   * transaction timestamp, in unix timestamp format, seconds
   */
  int64_t timestamp;
  /*
   * expiration timestamp in unix timestamp format
   * after that the transaction is invalid if it is not included in block yet
   */
  int64_t expiration_time;
};
#define COMMON__TX_HEADER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__tx_header__descriptor__chainmaker) \
    , (char *)protobuf_c_empty_string, NULL, COMMON__TX_TYPE__INVOKE_USER_CONTRACT, (char *)protobuf_c_empty_string, 0, 0 }


/*
 * query type transaction payload
 * TxType: QUERY_USER_CONTRACT & QUERY_SYSTEM_CONTRACT
 */
struct  _Common__QueryPayload
{
  ProtobufCMessage base;
  /*
   * smart contract name
   */
  char *contract_name;
  /*
   * query method
   */
  char *method;
  /*
   * query parameters in k-v format
   */
  size_t n_parameters;
  Common__KeyValuePair **parameters;
};
#define COMMON__QUERY_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__query_payload__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0,NULL }


/*
 * transact type transaction payload
 * TxType: INVOKE_USER_CONTRACT
 */
struct  _Common__TransactPayload
{
  ProtobufCMessage base;
  /*
   * smart contract name
   */
  char *contract_name;
  /*
   * invoke method
   */
  char *method;
  /*
   * invoke parameters in k-v format
   */
  size_t n_parameters;
  Common__KeyValuePair **parameters;
};
#define COMMON__TRANSACT_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__transact_payload__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0,NULL }


/*
 * config update type transaction payload
 * TxType: UPDATE_CHAIN_CONFIG
 */
struct  _Common__SystemContractPayload
{
  ProtobufCMessage base;
  /*
   * endorsement signature with chain_id, redundant with TxHeader
   */
  char *chain_id;
  /*
   * smart contract name
   */
  char *contract_name;
  /*
   * update method
   */
  char *method;
  /*
   * update parameters in k-v format
   */
  size_t n_parameters;
  Common__KeyValuePair **parameters;
  /*
   * config sequence, starts from 0 (genesis config)
   */
  uint64_t sequence;
  /*
   * multi-sign, signature of [SystemContractPayload] with endorsement = nil
   */
  size_t n_endorsement;
  Common__EndorsementEntry **endorsement;
};
#define COMMON__SYSTEM_CONTRACT_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__system_contract_payload__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0,NULL, 0, 0,NULL }


/*
 * contract management type transaction payload
 * TxType: MANAGE_USER_CONTRACT
 */
struct  _Common__ContractMgmtPayload
{
  ProtobufCMessage base;
  /*
   * endorsement signature with chain_id, redundant with TxHeader
   */
  char *chain_id;
  /*
   * smart contract id
   */
  Common__ContractId *contract_id;
  /*
   * contract management method, see ManageUserContractFunction
   */
  char *method;
  /*
   * parameters in k-v format
   */
  size_t n_parameters;
  Common__KeyValuePair **parameters;
  /*
   * compiled byte code
   */
  ProtobufCBinaryData byte_code;
  /*
   * multi-sign, signature of [ContractMgmtPayload] with endorsement = nil
   */
  size_t n_endorsement;
  Common__EndorsementEntry **endorsement;
};
#define COMMON__CONTRACT_MGMT_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__contract_mgmt_payload__descriptor) \
    , (char *)protobuf_c_empty_string, NULL, (char *)protobuf_c_empty_string, 0,NULL, {0,NULL}, 0,NULL }


/*
 * endorsement info, including a signer and his signature
 */
struct  _Common__EndorsementEntry
{
  ProtobufCMessage base;
  Accesscontrol__SerializedMember *signer;
  ProtobufCBinaryData signature;
};
#define COMMON__ENDORSEMENT_ENTRY__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__endorsement_entry__descriptor) \
    , NULL, {0,NULL} }


/*
 * a k-v pair
 */
struct  _Common__KeyValuePair
{
  ProtobufCMessage base;
  char *key;
  char *value;
};
#define COMMON__KEY_VALUE_PAIR__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__key_value_pair__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/*
 * subscribe contract event payload
 * TxType: SUBSCRIBE_CONTRACT_EVENT_INFO
 */
struct  _Common__SubscribeContractEventPayload
{
  ProtobufCMessage base;
  /*
   *event topic
   */
  char *topic;
  /*
   *contract name
   */
  char *contractname;
};
#define COMMON__SUBSCRIBE_CONTRACT_EVENT_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__subscribe_contract_event_payload__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string }


/*
 * subscribe block type transaction payload
 * TxType: SUBSCRIBE_BLOCK_INFO
 */
struct  _Common__SubscribeBlockPayload
{
  ProtobufCMessage base;
  /*
   * start block height:
   * < -1: invalid
   * == -1: subscribe with latest block
   * >= 0：starts with the block height
   */
  int64_t start_block;
  /*
   * end block height:
   * < -1: invalid
   * == -1: subscribe with latest block
   * >= 0：ends with the block height
   */
  int64_t end_block;
  /*
   * include rw set in block or not
   */
  protobuf_c_boolean with_rw_set;
};
#define COMMON__SUBSCRIBE_BLOCK_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__subscribe_block_payload__descriptor) \
    , 0, 0, 0 }


/*
 * subscribe transaction type transaction payload
 * TxType: SUBSCRIBE_TX_INFO
 */
struct  _Common__SubscribeTxPayload
{
  ProtobufCMessage base;
  /*
   * start block height:
   * < -1: invalid
   * == -1: subscribe with latest block
   * >= 0：starts with the block height
   */
  int64_t start_block;
  /*
   * end block height:
   * < -1: invalid
   * == -1: subscribe with latest block
   * >= 0：ends with the block height
   */
  int64_t end_block;
  /*
   * subscribe this type only
   * if null, subscribe all transaction types
   */
  Common__TxType tx_type;
  /*
   * subscribe these transaction ids only
   * if null, subscribe all transactions
   */
  size_t n_tx_ids;
  char **tx_ids;
};
#define COMMON__SUBSCRIBE_TX_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__subscribe_tx_payload__descriptor) \
    , 0, 0, COMMON__TX_TYPE__INVOKE_USER_CONTRACT, 0,NULL }


struct  _Common__ArchiveBlockPayload
{
  ProtobufCMessage base;
  int64_t block_height;
};
#define COMMON__ARCHIVE_BLOCK_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__archive_block_payload__descriptor) \
    , 0 }


struct  _Common__RestoreBlockPayload
{
  ProtobufCMessage base;
  ProtobufCBinaryData full_block;
};
#define COMMON__RESTORE_BLOCK_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__restore_block_payload__descriptor) \
    , {0,NULL} }


/* Common__TxRequest methods */
void   common__tx_request__init
                     (Common__TxRequest         *message);
size_t common__tx_request__get_packed_size
                     (const Common__TxRequest   *message);
size_t common__tx_request__pack
                     (const Common__TxRequest   *message,
                      uint8_t             *out);
size_t common__tx_request__pack_to_buffer
                     (const Common__TxRequest   *message,
                      ProtobufCBuffer     *buffer);
Common__TxRequest *
       common__tx_request__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__tx_request__free_unpacked
                     (Common__TxRequest *message,
                      ProtobufCAllocator *allocator);
/* Common__TxHeader methods */
void   common__tx_header__init__chainmaker
                     (Common__TxHeader         *message);
size_t common__tx_header__get_packed_size__chainmaker
                     (const Common__TxHeader   *message);
size_t common__tx_header__pack__chainmaker
                     (const Common__TxHeader   *message,
                      uint8_t             *out);
size_t common__tx_header__pack_to_buffer__chainmaker
                     (const Common__TxHeader   *message,
                      ProtobufCBuffer     *buffer);
Common__TxHeader *
       common__tx_header__unpack__chainmaker
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__tx_header__free_unpacked
                     (Common__TxHeader *message,
                      ProtobufCAllocator *allocator);
/* Common__QueryPayload methods */
void   common__query_payload__init
                     (Common__QueryPayload         *message);
size_t common__query_payload__get_packed_size
                     (const Common__QueryPayload   *message);
size_t common__query_payload__pack
                     (const Common__QueryPayload   *message,
                      uint8_t             *out);
size_t common__query_payload__pack_to_buffer
                     (const Common__QueryPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__QueryPayload *
       common__query_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__query_payload__free_unpacked
                     (Common__QueryPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__TransactPayload methods */
void   common__transact_payload__init
                     (Common__TransactPayload         *message);
size_t common__transact_payload__get_packed_size
                     (const Common__TransactPayload   *message);
size_t common__transact_payload__pack
                     (const Common__TransactPayload   *message,
                      uint8_t             *out);
size_t common__transact_payload__pack_to_buffer
                     (const Common__TransactPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__TransactPayload *
       common__transact_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__transact_payload__free_unpacked
                     (Common__TransactPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__SystemContractPayload methods */
void   common__system_contract_payload__init
                     (Common__SystemContractPayload         *message);
size_t common__system_contract_payload__get_packed_size
                     (const Common__SystemContractPayload   *message);
size_t common__system_contract_payload__pack
                     (const Common__SystemContractPayload   *message,
                      uint8_t             *out);
size_t common__system_contract_payload__pack_to_buffer
                     (const Common__SystemContractPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__SystemContractPayload *
       common__system_contract_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__system_contract_payload__free_unpacked
                     (Common__SystemContractPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__ContractMgmtPayload methods */
void   common__contract_mgmt_payload__init
                     (Common__ContractMgmtPayload         *message);
size_t common__contract_mgmt_payload__get_packed_size
                     (const Common__ContractMgmtPayload   *message);
size_t common__contract_mgmt_payload__pack
                     (const Common__ContractMgmtPayload   *message,
                      uint8_t             *out);
size_t common__contract_mgmt_payload__pack_to_buffer
                     (const Common__ContractMgmtPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__ContractMgmtPayload *
       common__contract_mgmt_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__contract_mgmt_payload__free_unpacked
                     (Common__ContractMgmtPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__EndorsementEntry methods */
void   common__endorsement_entry__init
                     (Common__EndorsementEntry         *message);
size_t common__endorsement_entry__get_packed_size
                     (const Common__EndorsementEntry   *message);
size_t common__endorsement_entry__pack
                     (const Common__EndorsementEntry   *message,
                      uint8_t             *out);
size_t common__endorsement_entry__pack_to_buffer
                     (const Common__EndorsementEntry   *message,
                      ProtobufCBuffer     *buffer);
Common__EndorsementEntry *
       common__endorsement_entry__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__endorsement_entry__free_unpacked
                     (Common__EndorsementEntry *message,
                      ProtobufCAllocator *allocator);
/* Common__KeyValuePair methods */
void   common__key_value_pair__init
                     (Common__KeyValuePair         *message);
size_t common__key_value_pair__get_packed_size
                     (const Common__KeyValuePair   *message);
size_t common__key_value_pair__pack
                     (const Common__KeyValuePair   *message,
                      uint8_t             *out);
size_t common__key_value_pair__pack_to_buffer
                     (const Common__KeyValuePair   *message,
                      ProtobufCBuffer     *buffer);
Common__KeyValuePair *
       common__key_value_pair__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__key_value_pair__free_unpacked
                     (Common__KeyValuePair *message,
                      ProtobufCAllocator *allocator);
/* Common__SubscribeContractEventPayload methods */
void   common__subscribe_contract_event_payload__init
                     (Common__SubscribeContractEventPayload         *message);
size_t common__subscribe_contract_event_payload__get_packed_size
                     (const Common__SubscribeContractEventPayload   *message);
size_t common__subscribe_contract_event_payload__pack
                     (const Common__SubscribeContractEventPayload   *message,
                      uint8_t             *out);
size_t common__subscribe_contract_event_payload__pack_to_buffer
                     (const Common__SubscribeContractEventPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__SubscribeContractEventPayload *
       common__subscribe_contract_event_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__subscribe_contract_event_payload__free_unpacked
                     (Common__SubscribeContractEventPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__SubscribeBlockPayload methods */
void   common__subscribe_block_payload__init
                     (Common__SubscribeBlockPayload         *message);
size_t common__subscribe_block_payload__get_packed_size
                     (const Common__SubscribeBlockPayload   *message);
size_t common__subscribe_block_payload__pack
                     (const Common__SubscribeBlockPayload   *message,
                      uint8_t             *out);
size_t common__subscribe_block_payload__pack_to_buffer
                     (const Common__SubscribeBlockPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__SubscribeBlockPayload *
       common__subscribe_block_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__subscribe_block_payload__free_unpacked
                     (Common__SubscribeBlockPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__SubscribeTxPayload methods */
void   common__subscribe_tx_payload__init
                     (Common__SubscribeTxPayload         *message);
size_t common__subscribe_tx_payload__get_packed_size
                     (const Common__SubscribeTxPayload   *message);
size_t common__subscribe_tx_payload__pack
                     (const Common__SubscribeTxPayload   *message,
                      uint8_t             *out);
size_t common__subscribe_tx_payload__pack_to_buffer
                     (const Common__SubscribeTxPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__SubscribeTxPayload *
       common__subscribe_tx_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__subscribe_tx_payload__free_unpacked
                     (Common__SubscribeTxPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__ArchiveBlockPayload methods */
void   common__archive_block_payload__init
                     (Common__ArchiveBlockPayload         *message);
size_t common__archive_block_payload__get_packed_size
                     (const Common__ArchiveBlockPayload   *message);
size_t common__archive_block_payload__pack
                     (const Common__ArchiveBlockPayload   *message,
                      uint8_t             *out);
size_t common__archive_block_payload__pack_to_buffer
                     (const Common__ArchiveBlockPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__ArchiveBlockPayload *
       common__archive_block_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__archive_block_payload__free_unpacked
                     (Common__ArchiveBlockPayload *message,
                      ProtobufCAllocator *allocator);
/* Common__RestoreBlockPayload methods */
void   common__restore_block_payload__init
                     (Common__RestoreBlockPayload         *message);
size_t common__restore_block_payload__get_packed_size
                     (const Common__RestoreBlockPayload   *message);
size_t common__restore_block_payload__pack
                     (const Common__RestoreBlockPayload   *message,
                      uint8_t             *out);
size_t common__restore_block_payload__pack_to_buffer
                     (const Common__RestoreBlockPayload   *message,
                      ProtobufCBuffer     *buffer);
Common__RestoreBlockPayload *
       common__restore_block_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__restore_block_payload__free_unpacked
                     (Common__RestoreBlockPayload *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Common__TxRequest_Closure)
                 (const Common__TxRequest *message,
                  void *closure_data);
typedef void (*Common__TxHeader_Closure)
                 (const Common__TxHeader *message,
                  void *closure_data);
typedef void (*Common__QueryPayload_Closure)
                 (const Common__QueryPayload *message,
                  void *closure_data);
typedef void (*Common__TransactPayload_Closure)
                 (const Common__TransactPayload *message,
                  void *closure_data);
typedef void (*Common__SystemContractPayload_Closure)
                 (const Common__SystemContractPayload *message,
                  void *closure_data);
typedef void (*Common__ContractMgmtPayload_Closure)
                 (const Common__ContractMgmtPayload *message,
                  void *closure_data);
typedef void (*Common__EndorsementEntry_Closure)
                 (const Common__EndorsementEntry *message,
                  void *closure_data);
typedef void (*Common__KeyValuePair_Closure)
                 (const Common__KeyValuePair *message,
                  void *closure_data);
typedef void (*Common__SubscribeContractEventPayload_Closure)
                 (const Common__SubscribeContractEventPayload *message,
                  void *closure_data);
typedef void (*Common__SubscribeBlockPayload_Closure)
                 (const Common__SubscribeBlockPayload *message,
                  void *closure_data);
typedef void (*Common__SubscribeTxPayload_Closure)
                 (const Common__SubscribeTxPayload *message,
                  void *closure_data);
typedef void (*Common__ArchiveBlockPayload_Closure)
                 (const Common__ArchiveBlockPayload *message,
                  void *closure_data);
typedef void (*Common__RestoreBlockPayload_Closure)
                 (const Common__RestoreBlockPayload *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    common__tx_type__descriptor__chainmaker;
extern const ProtobufCMessageDescriptor common__tx_request__descriptor;
extern const ProtobufCMessageDescriptor common__tx_header__descriptor__chainmaker;
extern const ProtobufCMessageDescriptor common__query_payload__descriptor;
extern const ProtobufCMessageDescriptor common__transact_payload__descriptor;
extern const ProtobufCMessageDescriptor common__system_contract_payload__descriptor;
extern const ProtobufCMessageDescriptor common__contract_mgmt_payload__descriptor;
extern const ProtobufCMessageDescriptor common__endorsement_entry__descriptor;
extern const ProtobufCMessageDescriptor common__key_value_pair__descriptor;
extern const ProtobufCMessageDescriptor common__subscribe_contract_event_payload__descriptor;
extern const ProtobufCMessageDescriptor common__subscribe_block_payload__descriptor;
extern const ProtobufCMessageDescriptor common__subscribe_tx_payload__descriptor;
extern const ProtobufCMessageDescriptor common__archive_block_payload__descriptor;
extern const ProtobufCMessageDescriptor common__restore_block_payload__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_common_2frequest_2eproto__INCLUDED */
