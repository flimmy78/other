/* soapStub.h
   Generated by gSOAP 2.7.6c from hreport.h
   Copyright (C) 2000-2005, Robert van Engelen, Genivia Inc. All Rights Reserved.
   This part of the software is released under one of the following licenses:
   GPL, the gSOAP public license, or Genivia's license for commercial use.
*/
#ifndef soapStub_H
#define soapStub_H
#include "stdsoap2.h"

/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/




#ifndef SOAP_TYPE__ns1__GetTemplate
#define SOAP_TYPE__ns1__GetTemplate (6)
/* ns1:GetTemplate */
class SOAP_CMAC _ns1__GetTemplate
{
public:
	int templateId;	/* required element of type xsd:int */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 6; } /* = unique id SOAP_TYPE__ns1__GetTemplate */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplate() { }
	virtual ~_ns1__GetTemplate() { }
};
#endif

#ifndef SOAP_TYPE_struct_1
#define SOAP_TYPE_struct_1 (18)
/* struct-1 */
struct struct_1
{
	char *__any;
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateResponse
#define SOAP_TYPE__ns1__GetTemplateResponse (7)
/* ns1:GetTemplateResponse */
class SOAP_CMAC _ns1__GetTemplateResponse
{
public:
	struct struct_1 *GetTemplateResult;	/* RPC return element */	/* optional element of type struct-1 */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 7; } /* = unique id SOAP_TYPE__ns1__GetTemplateResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateResponse() { }
	virtual ~_ns1__GetTemplateResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateConfig
#define SOAP_TYPE__ns1__GetTemplateConfig (8)
/* ns1:GetTemplateConfig */
class SOAP_CMAC _ns1__GetTemplateConfig
{
public:
	int templateId;	/* required element of type xsd:int */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 8; } /* = unique id SOAP_TYPE__ns1__GetTemplateConfig */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateConfig() { }
	virtual ~_ns1__GetTemplateConfig() { }
};
#endif

#ifndef SOAP_TYPE_struct_2
#define SOAP_TYPE_struct_2 (20)
/* struct-2 */
struct struct_2
{
	char *__any;
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateConfigResponse
#define SOAP_TYPE__ns1__GetTemplateConfigResponse (9)
/* ns1:GetTemplateConfigResponse */
class SOAP_CMAC _ns1__GetTemplateConfigResponse
{
public:
	struct struct_2 *GetTemplateConfigResult;	/* RPC return element */	/* optional element of type struct-2 */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 9; } /* = unique id SOAP_TYPE__ns1__GetTemplateConfigResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateConfigResponse() { }
	virtual ~_ns1__GetTemplateConfigResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__Query
#define SOAP_TYPE__ns1__Query (10)
/* ns1:Query */
class SOAP_CMAC _ns1__Query
{
public:
	int templateId;	/* required element of type xsd:int */
	int useSavedReport;	/* required element of type xsd:int */
	char *dateStartString;	/* optional element of type xsd:string */
	char *dateEndString;	/* optional element of type xsd:string */
	char *inputCells;	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 10; } /* = unique id SOAP_TYPE__ns1__Query */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__Query() { }
	virtual ~_ns1__Query() { }
};
#endif

#ifndef SOAP_TYPE_struct_3
#define SOAP_TYPE_struct_3 (22)
/* struct-3 */
struct struct_3
{
	char *__any;
};
#endif

#ifndef SOAP_TYPE__ns1__QueryResponse
#define SOAP_TYPE__ns1__QueryResponse (11)
/* ns1:QueryResponse */
class SOAP_CMAC _ns1__QueryResponse
{
public:
	struct struct_3 *QueryResult;	/* RPC return element */	/* optional element of type struct-3 */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 11; } /* = unique id SOAP_TYPE__ns1__QueryResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__QueryResponse() { }
	virtual ~_ns1__QueryResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateTree
#define SOAP_TYPE__ns1__GetTemplateTree (12)
/* ns1:GetTemplateTree */
class SOAP_CMAC _ns1__GetTemplateTree
{
public:
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE__ns1__GetTemplateTree */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateTree() { }
	virtual ~_ns1__GetTemplateTree() { }
};
#endif

#ifndef SOAP_TYPE_struct_4
#define SOAP_TYPE_struct_4 (24)
/* struct-4 */
struct struct_4
{
	char *__any;
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateTreeResponse
#define SOAP_TYPE__ns1__GetTemplateTreeResponse (13)
/* ns1:GetTemplateTreeResponse */
class SOAP_CMAC _ns1__GetTemplateTreeResponse
{
public:
	struct struct_4 *GetTemplateTreeResult;	/* RPC return element */	/* optional element of type struct-4 */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 13; } /* = unique id SOAP_TYPE__ns1__GetTemplateTreeResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateTreeResponse() { }
	virtual ~_ns1__GetTemplateTreeResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateInformation
#define SOAP_TYPE__ns1__GetTemplateInformation (14)
/* ns1:GetTemplateInformation */
class SOAP_CMAC _ns1__GetTemplateInformation
{
public:
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 14; } /* = unique id SOAP_TYPE__ns1__GetTemplateInformation */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateInformation() { }
	virtual ~_ns1__GetTemplateInformation() { }
};
#endif

#ifndef SOAP_TYPE_struct_5
#define SOAP_TYPE_struct_5 (26)
/* struct-5 */
struct struct_5
{
	char *__any;
};
#endif

#ifndef SOAP_TYPE__ns1__GetTemplateInformationResponse
#define SOAP_TYPE__ns1__GetTemplateInformationResponse (15)
/* ns1:GetTemplateInformationResponse */
class SOAP_CMAC _ns1__GetTemplateInformationResponse
{
public:
	struct struct_5 *GetTemplateInformationResult;	/* RPC return element */	/* optional element of type struct-5 */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE__ns1__GetTemplateInformationResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetTemplateInformationResponse() { }
	virtual ~_ns1__GetTemplateInformationResponse() { }
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplate
#define SOAP_TYPE___ns1__GetTemplate (31)
/* Operation wrapper: */
struct __ns1__GetTemplate
{
	_ns1__GetTemplate *ns1__GetTemplate;	/* optional element of type ns1:GetTemplate */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplateConfig
#define SOAP_TYPE___ns1__GetTemplateConfig (35)
/* Operation wrapper: */
struct __ns1__GetTemplateConfig
{
	_ns1__GetTemplateConfig *ns1__GetTemplateConfig;	/* optional element of type ns1:GetTemplateConfig */
};
#endif

#ifndef SOAP_TYPE___ns1__Query
#define SOAP_TYPE___ns1__Query (39)
/* Operation wrapper: */
struct __ns1__Query
{
	_ns1__Query *ns1__Query;	/* optional element of type ns1:Query */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplateTree
#define SOAP_TYPE___ns1__GetTemplateTree (43)
/* Operation wrapper: */
struct __ns1__GetTemplateTree
{
	_ns1__GetTemplateTree *ns1__GetTemplateTree;	/* optional element of type ns1:GetTemplateTree */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplateInformation
#define SOAP_TYPE___ns1__GetTemplateInformation (47)
/* Operation wrapper: */
struct __ns1__GetTemplateInformation
{
	_ns1__GetTemplateInformation *ns1__GetTemplateInformation;	/* optional element of type ns1:GetTemplateInformation */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplate_
#define SOAP_TYPE___ns1__GetTemplate_ (49)
/* Operation wrapper: */
struct __ns1__GetTemplate_
{
	_ns1__GetTemplate *ns1__GetTemplate;	/* optional element of type ns1:GetTemplate */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplateConfig_
#define SOAP_TYPE___ns1__GetTemplateConfig_ (51)
/* Operation wrapper: */
struct __ns1__GetTemplateConfig_
{
	_ns1__GetTemplateConfig *ns1__GetTemplateConfig;	/* optional element of type ns1:GetTemplateConfig */
};
#endif

#ifndef SOAP_TYPE___ns1__Query_
#define SOAP_TYPE___ns1__Query_ (53)
/* Operation wrapper: */
struct __ns1__Query_
{
	_ns1__Query *ns1__Query;	/* optional element of type ns1:Query */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplateTree_
#define SOAP_TYPE___ns1__GetTemplateTree_ (55)
/* Operation wrapper: */
struct __ns1__GetTemplateTree_
{
	_ns1__GetTemplateTree *ns1__GetTemplateTree;	/* optional element of type ns1:GetTemplateTree */
};
#endif

#ifndef SOAP_TYPE___ns1__GetTemplateInformation_
#define SOAP_TYPE___ns1__GetTemplateInformation_ (57)
/* Operation wrapper: */
struct __ns1__GetTemplateInformation_
{
	_ns1__GetTemplateInformation *ns1__GetTemplateInformation;	/* optional element of type ns1:GetTemplateInformation */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (60)
/* SOAP Header: */
struct SOAP_ENV__Header
{
	void *dummy;	/* transient */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (61)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
	char *SOAP_ENV__Value;	/* optional element of type QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (63)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
	char *__any;
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (64)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (65)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
	char *faultcode;	/* optional element of type QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (4)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif


/******************************************************************************\
 *                                                                            *
 * Typedef Synonyms                                                           *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Stubs                                                                      *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplate(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplate *ns1__GetTemplate, _ns1__GetTemplateResponse *ns1__GetTemplateResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplateConfig(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplateConfig *ns1__GetTemplateConfig, _ns1__GetTemplateConfigResponse *ns1__GetTemplateConfigResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Query(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__Query *ns1__Query, _ns1__QueryResponse *ns1__QueryResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplateTree(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplateTree *ns1__GetTemplateTree, _ns1__GetTemplateTreeResponse *ns1__GetTemplateTreeResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplateInformation(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplateInformation *ns1__GetTemplateInformation, _ns1__GetTemplateInformationResponse *ns1__GetTemplateInformationResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplate_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplate *ns1__GetTemplate, _ns1__GetTemplateResponse *ns1__GetTemplateResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplateConfig_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplateConfig *ns1__GetTemplateConfig, _ns1__GetTemplateConfigResponse *ns1__GetTemplateConfigResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__Query_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__Query *ns1__Query, _ns1__QueryResponse *ns1__QueryResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplateTree_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplateTree *ns1__GetTemplateTree, _ns1__GetTemplateTreeResponse *ns1__GetTemplateTreeResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetTemplateInformation_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetTemplateInformation *ns1__GetTemplateInformation, _ns1__GetTemplateInformationResponse *ns1__GetTemplateInformationResponse);

#endif

/* End of soapStub.h */
