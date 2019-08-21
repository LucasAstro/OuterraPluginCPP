#pragma once

#ifndef __INTERGEN_GENERATED__engine_JS_H__
#define __INTERGEN_GENERATED__engine_JS_H__

//@file Javascript interface file for engine interface generated by intergen
//See LICENSE file for copyright and license information

#include "engine.h"

#include <comm/intergen/ifc.js.h>
#include <comm/token.h>

namespace xt {
namespace js {

class engine
{
public:

    ///Interface creator
    //@param scriptpath path to js script to bind to
    static iref<xt::engine> get( const ::js::script_handle& script, const coid::token& bindvar = coid::token(), v8::Handle<v8::Context>* ctx=0 )
    {
        typedef iref<xt::engine> (*fn_bind)(const ::js::script_handle&, const coid::token&, v8::Handle<v8::Context>*);
        static fn_bind binder = 0;
        static const coid::token ifckey = "xt::engine.get@creator.js";

        if (!binder)
            binder = reinterpret_cast<fn_bind>(
                coid::interface_register::get_interface_creator(ifckey));

        if (!binder)
            throw coid::exception("interface binder inaccessible: ") << ifckey;

        return binder(script, bindvar, ctx);
    }
};

} //namespace js
} //namespace


#endif //__INTERGEN_GENERATED__engine_JS_H__
