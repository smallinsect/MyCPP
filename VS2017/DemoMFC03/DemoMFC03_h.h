

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for DemoMFC03.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __DemoMFC03_h_h__
#define __DemoMFC03_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDemoMFC03_FWD_DEFINED__
#define __IDemoMFC03_FWD_DEFINED__
typedef interface IDemoMFC03 IDemoMFC03;

#endif 	/* __IDemoMFC03_FWD_DEFINED__ */


#ifndef __CDemoMFC03Doc_FWD_DEFINED__
#define __CDemoMFC03Doc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDemoMFC03Doc CDemoMFC03Doc;
#else
typedef struct CDemoMFC03Doc CDemoMFC03Doc;
#endif /* __cplusplus */

#endif 	/* __CDemoMFC03Doc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __DemoMFC03_LIBRARY_DEFINED__
#define __DemoMFC03_LIBRARY_DEFINED__

/* library DemoMFC03 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DemoMFC03;

#ifndef __IDemoMFC03_DISPINTERFACE_DEFINED__
#define __IDemoMFC03_DISPINTERFACE_DEFINED__

/* dispinterface IDemoMFC03 */
/* [uuid] */ 


EXTERN_C const IID DIID_IDemoMFC03;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("c33bbc6d-e547-45c5-9d31-ed55f8073f5a")
    IDemoMFC03 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IDemoMFC03Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDemoMFC03 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDemoMFC03 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDemoMFC03 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDemoMFC03 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDemoMFC03 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDemoMFC03 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDemoMFC03 * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } IDemoMFC03Vtbl;

    interface IDemoMFC03
    {
        CONST_VTBL struct IDemoMFC03Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDemoMFC03_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDemoMFC03_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDemoMFC03_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDemoMFC03_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDemoMFC03_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDemoMFC03_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDemoMFC03_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IDemoMFC03_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDemoMFC03Doc;

#ifdef __cplusplus

class DECLSPEC_UUID("4145fed4-dc84-439b-b3bb-db4cd31a1dea")
CDemoMFC03Doc;
#endif
#endif /* __DemoMFC03_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


