#include <mruby.h>
#include <mruby/string.h>
#include "sha1.h"

static struct RClass *_class_sha1;

/*********************************************************
 * main
 *********************************************************/

static char
nr2char(int n) {
  if (0 <= n && n <= 9) {
    return '0' + n;
  } else {
    return 'a' + n - 10;
  }
}

static mrb_value
mrb_sha1_hex(mrb_state *mrb, mrb_value self)
{
  unsigned char digest[16];
  unsigned char digest_hex[33];
  mrb_value arg = mrb_nil_value();
  int i;

  mrb_get_args(mrb, "o", &arg);
  if (mrb_nil_p(arg) || mrb_type(arg) != MRB_TT_STRING) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "invalid argument");
  }

  struct sha1_context ctx;
  sha1_starts(&ctx);
  sha1_update(&ctx, (uint8*) RSTRING_PTR(arg), RSTRING_LEN(arg));
  sha1_finish(&ctx, (uint8*)&digest[0]);

  for (i = 0; i < 16; i++) {
    digest_hex[i*2+0] = nr2char((digest[i] >> 4) & 0xf);
    digest_hex[i*2+1] = nr2char(digest[i] & 0x0f);
  }
  digest_hex[32] = 0;

  return mrb_str_new(mrb, (char*) digest_hex, 32);
}

/*********************************************************
 * register
 *********************************************************/

void
mrb_mruby_sha1_gem_init(mrb_state* mrb) {
  _class_sha1 = mrb_define_module(mrb, "SHA1");
  mrb_define_class_method(mrb, _class_sha1, "sha1_hex", mrb_sha1_hex, ARGS_REQ(1));
}

/* vim:set et ts=2 sts=2 sw=2 tw=0: */
