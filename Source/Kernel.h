#ifndef TPKIT_KERNEL_H_
#define TPKIT_KERNEL_H_

#include <stddef.h>
#include <stdint.h>

#include "API.h"

#ifndef __cplusplus
extern "C" {
#endif  // __cplusplus

enum TPKit_Kernel__TaskKind {
  TPKit_Kernel__TaskKind_Auto = 0,
};

enum TPKit_Kernel__TaskEventKind {
  TPKit_Kernel__TaskEventKind_Error = 0,
  TPKit_Kernel__TaskEventKind_Done,
  TPKit_Kernel__TaskEventKind_Progress,
  TPKit_Kernel__TaskEventKind_Suspend,
  TPKit_Kernel__TaskEventKind_Resume,
  TPKit_Kernel__TaskEventKind_Start,
  TPKit_Kernel__TaskEventKind_Stop,
};

typedef enum TPKit_Kernel__TaskKind TPKit_Kernel__TaskKind;
typedef enum TPKit_Kernel__TaskEventKind TPKit_Kernel__TaskEventKind;
typedef struct TPKit_Kernel__TaskListener TPKit_Kernel__TaskListener;
typedef struct TPKit_Kernel__TaskEvent TPKit_Kernel__TaskEvent;

struct TPKit_Kernel__TaskEvent {
  int32_t task_id;
  int32_t clip_no;
  TPKit_Kernel__TaskEventKind kind;
};

struct TPKit_Kernel__TaskListener {
  void (*OnTaskEvent)(TPKit_Kernel__TaskEvent);
};

TPKIT_API int TPKit_Kernel__Init();
TPKIT_API int TPKit_Kernel__Drop();
TPKIT_API int32_t TPKit_Kernel__CreateTask(TPKit_Kernel__TaskKind,
                                           TPKit_Kernel__TaskListener *);
TPKIT_API int TPKit_Kernel__StopTask(int32_t);
TPKIT_API int TPKit_Kernel__SuspendTask(int32_t);
TPKIT_API int TPKit_Kernel__ResumeTask(int32_t);
TPKIT_API int TPKit_Kernel__GetProxyURL(int32_t, int32_t);

#ifndef __cplusplus
}
#endif  // __cplusplus

#endif  // TPKIT_KERNEL_H_
