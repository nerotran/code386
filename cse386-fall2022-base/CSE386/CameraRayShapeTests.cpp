#include "camera.h"
#include "ishape.h"
#include "io.h"

/*
 Experimenting with cameras and with viewing rays
 */
void cameraRayTests() {

    dvec3 camPos(0, 0, 0);
    dvec3 camLookPt(0, 0, -2);
    dvec3 up(0, 1, 0);
    double fov = glm::radians(45.0); // only for perspective cameras
    int scale = 1; // only for orthographic cameras (PPWU on worksheet)
    int nx = 200;
    int ny = 200;

    //PerspectiveCamera cam(camPos, camLookPt, up, fov, nx, ny);
    OrthographicCamera cam(camPos, camLookPt, up, nx, ny, scale);

    // Check that the frame is what we expect (pos, u, v, w)
    //Frame frame = cam.getFrame();
    //cout << frame << endl;


    // Check that the image plane is what we expect (top, bottom, left, right)
    // (and distToPlane for perspective cameras)
    // cout << cam.getDistToPlane() << endl; // perspective only
/*    cout << cam.getTop() << endl;
    cout << cam.getBottom() << endl;
    cout << cam.getLeft() << endl;
    cout << cam.getRight() << endl;  */

    //*******************************************
    //Ray experiments...set aside camera for a moment

    // Create a ray with origin at (0, 0, 0) and direction (7, 0, 0)
    // How is a ray different from a vector?
    //Ray ray(dvec3(5, 1, 10), dvec3(7, 0, 0));
    //cout << ray.origin << ray.dir << endl;



    // Check its origin and direction
    // Note that these are relative to WORLD coordinates and frame (not camera frame)



    // The parametric equation of the ray is:
    // p(t) = origin + t * dir       (dir is normalized)
   // cout << ray.getPoint(0) << endl;
  //  cout << ray.getPoint(1) << endl;
  //  cout << ray.getPoint(27) << endl;


    //*******************************************
    // Our camera gives us back rays.
    // Each pixel in the rendering window has a corresponding ray through the image plane
    // WARNING: getRay() requires that map() is correctly implemented in utilities.cpp



    // **** Stop for some math ****
    // 1. How do we take a pixel (x,y) in the rendering window and
    // compute its corresponding coordinates in the image plane?
    // (calculations are the same for both camera types)
    Ray r = cam.getRay(100, 100); // gets me the viewing ray for pixel (0, 0)
    cout << r.origin << endl;
    cout << r.origin << endl;
    cout << r.dir << endl;


    // 2. How do we take a pixel (x,y) in the rendering window and
    // compute its corresponding viewing ray through the image (origin and angle)?
    // (perspective calculations are different from orthographic calculations)

}

/*
 Experimenting with viewing rays to see if they intersect spheres.
 */
void rayShapeTests() {

    dvec3 camPos(0, 0, 0);
    dvec3 camLookPt(20, 0, 0);
    dvec3 up(0, 1, 0);
    double fov = glm::radians(45.0); // only for perspective cameras
    int scale = 1; // only for orthographic cameras
    int nx = 200;
    int ny = 200;

    PerspectiveCamera cam(camPos, camLookPt, up, fov, nx, ny);


    // ******* Ignore the camera for now

    // Ray - Object intersection: spheres
    // Create a sphere at (20, 0, 0) with a radius of 5
    ISphere sphere(dvec3(20, 0, 0), 5);

    // Create a ray with origin (0, 0, 0) looking in the direction (1, 0, 0)
    Ray ray(dvec3(0, 0, 0), dvec3(1, 0, 0));

    // Intuitively: Does this ray intersect this sphere?
    // How can we check with code?
    // WARNING: only works if quadratic(a, b, c, double[2]) is working
    HitRecord hits[2]; // stores data about the hits including t, and inters. pt.
    int hitCount = sphere.findIntersections(ray, hits);

    cout << "hits: " << hitCount << endl;

    // If hitCount > 0, then we can expect the array to have data about the hit(s),
    // sorted by t value.
    cout << hits[0].t << endl;
    cout << hits[1].t << endl;

    // Locations of the hits. Again, these are only valid if there are hits.
    cout << hits[0].interceptPt << endl;
    cout << hits[1].interceptPt << endl;

    // Can my camera see the sphere? Remember that the camera has a getRay() that
    // takes a pixel (x, y) and gives back the viewing ray for that pixel. So, for
    // example, if the rendering window has 40,000 pixels, then the camera can
    // generate 40,000 viewing rays (one for each pixel). Each of those can be checked
    // to see which objects it intersects.


    // Here is code for checking pixel (100, 100) to see if the corresponding
    // ray hits the sphere.
    cout << sphere.findIntersections(cam.getRay(100, 100), hits);

}


int old_main2(int argc, char* argv[]) {
    cout << "testing..." << endl;
    //cameraRayTests();
    rayShapeTests();

    return 0;

}