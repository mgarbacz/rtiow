#include "camera.h"
#include "color.h"
#include "hittable_list.h"
#include "material.h"
#include "math_utils.h"
#include "sphere.h"
#include "vec3.h"

#include <memory>

using std::make_shared;

int main() {
  hittable_list world;

  auto mat_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
  auto mat_center = make_shared<lambertian>(color(0.7, 0.3, 0.3));
  auto mat_left   = make_shared<metal>(color(0.8, 0.8, 0.8));
  auto mat_right  = make_shared<metal>(color(0.8, 0.6, 0.2));

  world.add(make_shared<sphere>(point3( 0.0, -100.5, -1.0), 100.0, mat_ground));
  world.add(make_shared<sphere>(point3( 0.0,    0.0, -1.0),   0.5, mat_center));
  world.add(make_shared<sphere>(point3(-1.0,    0.0, -1.0),   0.5, mat_left));
  world.add(make_shared<sphere>(point3( 1.0,    0.0, -1.0),   0.5, mat_right));

  camera cam;

  cam.aspect_ratio      = 16.0 / 9.0;
  cam.image_width       = 400;
  cam.samples_per_pixel = 100;
  cam.max_depth         = 50;

  cam.render(world);
}
