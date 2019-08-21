#pragma once

#ifndef __INTERGEN_GENERATED__sndgrp_H__
#define __INTERGEN_GENERATED__sndgrp_H__

//@file Interface file for sndgrp interface generated by intergen
//See LICENSE file for copyright and license information

//host class: ::snd::group

#include <comm/commexception.h>
#include <comm/intergen/ifc.h>

namespace snd { class group; }

#include <ot/sound_cfg.h>

namespace snd {
    class group;
}

namespace ot {

////////////////////////////////////////////////////////////////////////////////

///Interface 
class sndgrp
    : public intergen_interface
{
public:

    // --- interface methods ---

    ///Load sound files from object or package directory
    //@param filename relative path to the sound file
    //@note in case of an independent sound group, filename refers to the relative path in data or program directory
    uint load_sound( const coid::token& filename );

    ///
    //@param bone bone id
    //@param type sound type
    uint create_source( uint bone, ot::sound_type type = ot::sound_type::universal );

    uint create_source_wo_bone( ot::sound_type type = ot::sound_type::universal );

    /// set source ECEF position once it's used source always be using ECEF
    void set_source_ecef( uint source_id, const double3& pos );

    /// 
    void play( uint id, uint snd, bool looping, bool enqueue, bool break_prev_loops = true );

    /// Play sound once, discarding older sounds
    void play_sound( uint id, uint snd );

    /// Play looped sound, breaking other sounds
    void play_loop( uint id, uint snd );

    /// Enqueue sound once, previous loops are finished and then discarded
    void enqueue_sound( uint id, uint snd );

    /// Enqueue looped sound. If @break_prev_loops is true, previous loops are removed after completion,
    /// and only this sound remains looped. Otherwise the new sound is added to the loop chain.
    void enqueue_loop( uint id, uint snd, bool break_prev_loops = true );

    ///
    bool is_playing( uint id );

    bool is_looping( uint id );

    void stop( uint id );

    ///
    void set_pitch( uint id, float pitch );

    /// Open AL distance attenuation model
    /// https://www.desmos.com/calculator/f20nyvlupa
    void set_ref_distance( uint id, float ref_dist );

    ///
    void set_gain( uint id, float gain );

    // --- creators ---

    ///Internal constructor
    static iref<sndgrp> _get_sndgrp( snd::group* p ) {
        return _get_sndgrp<sndgrp>(0, p);
    }

    template<class T>
    static iref<T> _get_sndgrp( T* _subclass_, snd::group* p );

    ///Create a sound group object
    //@note 
    static iref<sndgrp> create() {
        return create<sndgrp>(0);
    }

    template<class T>
    static iref<T> create( T* _subclass_ );

    // --- internal helpers ---

    ///Interface revision hash
    static const int HASHID = 1696759525;

    ///Interface name (full ns::class string)
    static const coid::tokenhash& IFCNAME() {
        static const coid::tokenhash _name = "ot::sndgrp";
        return _name;
    }

    int intergen_hash_id() const override final { return HASHID; }

    bool iface_is_derived( int hash ) const override final {
        return hash == HASHID;
    }

    const coid::tokenhash& intergen_interface_name() const override final {
        return IFCNAME();
    }

    static const coid::token& intergen_default_creator_static( EBackend bck ) {
        static const coid::token _dc("ot::sndgrp.create@1696759525");
        static const coid::token _djs("ot::sndgrp@wrapper.js");
        static const coid::token _djsc("ot::sndgrp@wrapper.jsc");
        static const coid::token _dlua("ot::sndgrp@wrapper.lua");
        static const coid::token _dnone;

        switch(bck) {
        case IFC_BACKEND_CXX: return _dc;
        case IFC_BACKEND_JS:  return _djs;
        case IFC_BACKEND_JSC:  return _djsc;
        case IFC_BACKEND_LUA: return _dlua;
        default: return _dnone;
        }
    }

    template<enum EBackend B>
    static void* intergen_wrapper_cache() {
        static void* _cached_wrapper=0;
        if (!_cached_wrapper) {
            const coid::token& tok = intergen_default_creator_static(B);
            _cached_wrapper = coid::interface_register::get_interface_creator(tok);
        }
        return _cached_wrapper;
    }

    void* intergen_wrapper( EBackend bck ) const override final {
        switch(bck) {
        case IFC_BACKEND_JS: return intergen_wrapper_cache<IFC_BACKEND_JS>();
        case IFC_BACKEND_JSC: return intergen_wrapper_cache<IFC_BACKEND_JSC>();
        case IFC_BACKEND_LUA: return intergen_wrapper_cache<IFC_BACKEND_LUA>();
        default: return 0;
        }
    }

    EBackend intergen_backend() const override { return IFC_BACKEND_CXX; }

    const coid::token& intergen_default_creator( EBackend bck ) const override final {
        return intergen_default_creator_static(bck);
    }

    ///Client registrator
    template<class C>
    static int register_client()
    {
        static_assert(std::is_base_of<sndgrp, C>::value, "not a base class");

        typedef iref<intergen_interface> (*fn_client)(void*, intergen_interface*);
        fn_client cc = [](void*, intergen_interface*) -> iref<intergen_interface> { return new C; };

        coid::token type = typeid(C).name();
        type.consume("class ");
        type.consume("struct ");

        coid::charstr tmp = "ot::sndgrp";
        tmp << "@client-1696759525" << '.' << type;

        coid::interface_register::register_interface_creator(tmp, cc);
        return 0;
    }

protected:

    sndgrp()
    {}
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> sndgrp::_get_sndgrp( T* _subclass_, snd::group* p )
{
    typedef iref<T> (*fn_creator)(sndgrp*, snd::group*);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::sndgrp._get_sndgrp@1696759525";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("_get_sndgrp", "ot::sndgrp._get_sndgrp", "@1696759525");
        return 0;
    }

    return create(_subclass_, p);
}

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline iref<T> sndgrp::create( T* _subclass_ )
{
    typedef iref<T> (*fn_creator)(sndgrp*);

    static fn_creator create = 0;
    static const coid::token ifckey = "ot::sndgrp.create@1696759525";

    if (!create)
        create = reinterpret_cast<fn_creator>(
            coid::interface_register::get_interface_creator(ifckey));

    if (!create) {
        log_mismatch("create", "ot::sndgrp.create", "@1696759525");
        return 0;
    }

    return create(_subclass_);
}

#pragma warning(push)
#pragma warning(disable : 4191)

inline uint sndgrp::load_sound( const coid::token& filename )
{ return VT_CALL(uint,(const coid::token&),0)(filename); }

inline uint sndgrp::create_source( uint bone, ot::sound_type type )
{ return VT_CALL(uint,(uint,ot::sound_type),1)(bone,type); }

inline uint sndgrp::create_source_wo_bone( ot::sound_type type )
{ return VT_CALL(uint,(ot::sound_type),2)(type); }

inline void sndgrp::set_source_ecef( uint source_id, const double3& pos )
{ return VT_CALL(void,(uint,const double3&),3)(source_id,pos); }

inline void sndgrp::play( uint id, uint snd, bool looping, bool enqueue, bool break_prev_loops )
{ return VT_CALL(void,(uint,uint,bool,bool,bool),4)(id,snd,looping,enqueue,break_prev_loops); }

inline void sndgrp::play_sound( uint id, uint snd )
{ return VT_CALL(void,(uint,uint),5)(id,snd); }

inline void sndgrp::play_loop( uint id, uint snd )
{ return VT_CALL(void,(uint,uint),6)(id,snd); }

inline void sndgrp::enqueue_sound( uint id, uint snd )
{ return VT_CALL(void,(uint,uint),7)(id,snd); }

inline void sndgrp::enqueue_loop( uint id, uint snd, bool break_prev_loops )
{ return VT_CALL(void,(uint,uint,bool),8)(id,snd,break_prev_loops); }

inline bool sndgrp::is_playing( uint id )
{ return VT_CALL(bool,(uint),9)(id); }

inline bool sndgrp::is_looping( uint id )
{ return VT_CALL(bool,(uint),10)(id); }

inline void sndgrp::stop( uint id )
{ return VT_CALL(void,(uint),11)(id); }

inline void sndgrp::set_pitch( uint id, float pitch )
{ return VT_CALL(void,(uint,float),12)(id,pitch); }

inline void sndgrp::set_ref_distance( uint id, float ref_dist )
{ return VT_CALL(void,(uint,float),13)(id,ref_dist); }

inline void sndgrp::set_gain( uint id, float gain )
{ return VT_CALL(void,(uint,float),14)(id,gain); }

#pragma warning(pop)

} //namespace

#endif //__INTERGEN_GENERATED__sndgrp_H__
