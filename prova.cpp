#include "th_lib.h"
#include "th_al.h"
#include "al_smp.h"
#include "mith_sync.h"
#include "mith_workload.h"


extern void *define_params(unsigned int idx, char *name, char *dataset);
extern void *init_func(void *);
extern void *bench_func(struct TCDef *,void *);
extern void *veri_func(void *);

int main() {
	TCDef benchin;
    void *retval;
    void *params;

    // Define params
    retval = define_params_nnet(0, "nnet", "0");

    // Init
    params=init_func(retval);

    // Bench init
    // todo understand how to initialize tcdef
    th_memcpy(&benchin, &benchin,sizeof(TCDef));

    // Bench run
    bench_func(&benchin,params);
    Bool failed = (Bool)(veri_func(params)<=0);

	return 0;
}