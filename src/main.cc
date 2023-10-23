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

  auto R = cos(pi /4 );

  auto material_left  = make_shared<lambertian>(color(0, 0, 1));
  auto material_right = make_shared<lambertian>(color(1, 0, 0));

  world.add(make_shared<sphere>(point3(-R, 0, -1), R, material_left));
  world.add(make_shared<sphere>(point3( R, 0, -1), R, material_right));

  camera cam;

  cam.aspect_ratio      = 16.0 / 9.0;
  cam.image_width       = 400;
  cam.samples_per_pixel = 100;
  cam.max_depth         = 50;

  cam.vfov     = 90;
  cam.lookfrom = point3(-2, 2, 1);
  cam.lookat   = point3(0, 0, -1);
  cam.vup      = vec3(0, 1, 0);

  cam.render(world);
}
