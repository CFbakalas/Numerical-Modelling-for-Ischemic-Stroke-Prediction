#include "udf.h"

/* ================= TOP LEFT ================= */
DEFINE_PROFILE(INLET_TL, thread, position)
{
    real x[ND_ND];
    real R = 0.00143;
    real r;
    real x_c = -0.0082554586;
    real y_c = 0.063242937;
    real v_max = 1.29107e-5;

    face_t f;

    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);

        r = sqrt( (x[0]-x_c)*(x[0]-x_c)
                + (x[1]-y_c)*(x[1]-y_c) );

        F_PROFILE(f, thread, position) =
            v_max * (1.0 - (r*r)/(R*R));
    }
    end_f_loop(f, thread)
}


/* ================= TOP RIGHT ================= */
DEFINE_PROFILE(INLET_TR, thread, position)
{
    real x[ND_ND];
    real R = 0.00143;
    real r;
    real x_c = 0.063251113;
    real y_c = 0.063242572;
    real v_max = 1.29107e-5;

    face_t f;

    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);

        r = sqrt( (x[0]-x_c)*(x[0]-x_c)
                + (x[1]-y_c)*(x[1]-y_c) );

        F_PROFILE(f, thread, position) =
            v_max * (1.0 - (r*r)/(R*R));
    }
    end_f_loop(f, thread)
}


/* ================= BOTTOM LEFT ================= */
DEFINE_PROFILE(INLET_BL, thread, position)
{
    real x[ND_ND];
    real R = 0.00143;
    real r;
    real x_c = -0.0082572731;
    real y_c = -0.0082552539;
    real v_max = 1.29107e-5;

    face_t f;

    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);

        r = sqrt( (x[0]-x_c)*(x[0]-x_c)
                + (x[1]-y_c)*(x[1]-y_c) );

        F_PROFILE(f, thread, position) =
            v_max * (1.0 - (r*r)/(R*R));
    }
    end_f_loop(f, thread)
}


/* ================= BOTTOM RIGHT ================= */
DEFINE_PROFILE(INLET_BR, thread, position)
{
    real x[ND_ND];
    real R = 0.00143;
    real r;
    real x_c = 0.063243669;   
    real y_c = -0.0082564269;
    real v_max = 1.29107e-5;

    face_t f;

    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);

        r = sqrt( (x[0]-x_c)*(x[0]-x_c)
                + (x[1]-y_c)*(x[1]-y_c) );

        F_PROFILE(f, thread, position) =
            v_max * (1.0 - (r*r)/(R*R));
    }
    end_f_loop(f, thread)
}
/* ================= VENULE ================= */
DEFINE_PROFILE(VENULE, thread, position)
{
    real x[ND_ND];
    real R = 0.0066;
    real r;
    real x_c = 0.027495018;
    real y_c = 0.027499675;
    real v_max = 1.29107e-5;

    face_t f;

    begin_f_loop(f, thread)
    {
        F_CENTROID(x, f, thread);

        r = sqrt( (x[0]-x_c)*(x[0]-x_c)
                + (x[1]-y_c)*(x[1]-y_c) );

        F_PROFILE(f, thread, position) =
            v_max * (1.0 - (r*r)/(R*R));
    }
    end_f_loop(f, thread)
}
