/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: common/transaction.proto */

#ifndef PROTOBUF_C_common_2ftransaction_2eproto__INCLUDED
#define PROTOBUF_C_common_2ftransaction_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1003003 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "common/request.pb-c.h"
#include "common/result.pb-c.h"

typedef struct _Common__Transaction Common__Transaction;
typedef struct _Common__TransactionInfo Common__TransactionInfo;


/* --- enums --- */


/* --- messages --- */

/*
 * a transaction includes request and its result
 */
struct  _Common__Transaction
{
  ProtobufCMessage base;
  /*
   * header of the transaction
   */
  Common__TxHeader *header;
  /*
   * payload of the request
   */
  ProtobufCBinaryData request_payload;
  /*
   * signature of request bytes(including header and payload)
   */
  ProtobufCBinaryData request_signature;
  /*
   * result of the transaction, can be marshalled according to tx_type in header
   */
  Common__Result *result;
};
#define COMMON__TRANSACTION__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__transaction__descriptor__chainmaker) \
    , NULL, {0,NULL}, {0,NULL}, NULL }


/*
 * transactioninfo inclde transaction and its block height hash and tx index
 */
struct  _Common__TransactionInfo
{
  ProtobufCMessage base;
  /*
   * transaction raw data
   */
  Common__Transaction *transaction;
  /*
   * block height
   */
  uint64_t block_height;
  /*
   * block hash
   */
  ProtobufCBinaryData block_hash;
  /*
   * transaction index in block
   */
  uint32_t tx_index;
};
#define COMMON__TRANSACTION_INFO__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&common__transaction_info__descriptor) \
    , NULL, 0, {0,NULL}, 0 }


/* Common__Transaction methods */
void   common__transaction__init
                     (Common__Transaction         *message);
size_t common__transaction__get_packed_size
                     (const Common__Transaction   *message);
size_t common__transaction__pack
                     (const Common__Transaction   *message,
                      uint8_t             *out);
size_t common__transaction__pack_to_buffer
                     (const Common__Transaction   *message,
                      ProtobufCBuffer     *buffer);
Common__Transaction *
       common__transaction__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__transaction__free_unpacked__chainmaker
                     (Common__Transaction *message,
                      ProtobufCAllocator *allocator);
/* Common__TransactionInfo methods */
void   common__transaction_info__init
                     (Common__TransactionInfo         *message);
size_t common__transaction_info__get_packed_size
                     (const Common__TransactionInfo   *message);
size_t common__transaction_info__pack
                     (const Common__TransactionInfo   *message,
                      uint8_t             *out);
size_t common__transaction_info__pack_to_buffer
                     (const Common__TransactionInfo   *message,
                      ProtobufCBuffer     *buffer);
Common__TransactionInfo *
       common__transaction_info__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   common__transaction_info__free_unpacked
                     (Common__TransactionInfo *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Common__Transaction_Closure)
                 (const Common__Transaction *message,
                  void *closure_data);
typedef void (*Common__TransactionInfo_Closure)
                 (const Common__TransactionInfo *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor common__transaction__descriptor__chainmaker;
extern const ProtobufCMessageDescriptor common__transaction_info__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_common_2ftransaction_2eproto__INCLUDED */
