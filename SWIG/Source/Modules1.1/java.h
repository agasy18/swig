
// ------------------------------------------------------------------------
// A Java SWIG Language module
//
// ------------------------------------------------------------------------

class JAVA : public Language {
public :

  // Virtual functions required by the SWIG parser

  virtual void main(int, char *argv[]);
  virtual int top(Node *); 
  virtual int functionWrapper(Node *);
  virtual int constantWrapper(Node *);
  virtual int variableWrapper(Node *);
  virtual int nativeWrapper(Node *);
  virtual int staticmemberfunctionHandler(Node *);
  virtual int staticmembervariableHandler(Node *);
  virtual int membervariableHandler(Node *);
  virtual int enumDeclaration(Node *n);
  virtual int memberconstantHandler(Node *);
  virtual int memberfunctionHandler(Node *);
  virtual int constructorHandler(Node *);
  virtual int destructorHandler(Node *);
  virtual int classHandler(Node *);
  virtual int classforwardDeclaration(Node *);

  virtual void set_module(char *);                 /* Deprecated */
  virtual void pragma(char *lang, char *code, char *value);

  /* Java module enums */
  enum type_additions {none, pointer, reference};

  /* Java module methods */
  void emit_classdef();
  void emit_shadow_classdef(char* c_classname,char* c_baseclassname);
  char *JNICALL(DOHString_or_char *func);
  char *makeValidJniName(const char *name);
  char *JavaMethodSignature(SwigType *t, int ret, int inShadow);
  void writeRegisterNatives();
  void javashadowfunctionHandler(Node* n, int is_virtual);
  void TypemapApply(String *swigtype, String *tmap, String *name, type_additions additions, int array_flag);

};
