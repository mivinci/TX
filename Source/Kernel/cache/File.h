#pragma once
#include "Kernel/Def.h"
#include "Kernel/Result.h"

namespace TP::cache {
class File {
public:
  explicit File(int32_t task_id) : task_id_(task_id) {}

  TP_ISIZE readClip(int32_t clip_no, int32_t start, TP_USIZE end, char *buf,
                    TP_USIZE buf_size);
  TP_ISIZE writeClip(int32_t clip_no, int32_t start, TP_USIZE end, char *buf,
                     TP_USIZE buf_size);
  TP_RESULT flushClip(int32_t clip_no);

private:
  int32_t task_id_;
};
} // namespace TP::cache
