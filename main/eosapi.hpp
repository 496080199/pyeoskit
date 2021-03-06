/*
 * eosapi.hpp
 *
 *  Created on: Oct 8, 2018
 *      Author: newworld
 */

#ifndef MAIN_EOSAPI_HPP_
#define MAIN_EOSAPI_HPP_

#include <vector>
#include <stdint.h>
#include <Python.h>

#include <eosio/chain/name.hpp>
#include <eosio/chain/action.hpp>
#include <eosio/chain/abi_serializer.hpp>
#include <fc/io/json.hpp>

using namespace std;
using namespace eosio;
using namespace eosio::chain;

uint64_t s2n_(string& str);
void n2s_(uint64_t n, string& s);

void pack_args_(string& rawabi, uint64_t action, string& _args, string& binargs);
void unpack_args_( string& rawabi, uint64_t action, string& binargs, string& _args );
void pack_abi_(string& _abi, string& out);

PyObject* gen_transaction_(vector<chain::action>& v, int expiration, string& reference_block_id);
PyObject* sign_transaction_(string& trx_json_to_sign, string& str_private_key, string& chain_id);
PyObject* pack_transaction_(string& _signed_trx, int compress);

#endif /* MAIN_EOSAPI_HPP_ */
