#include <iostream>
#include <string>
using namespace std;

string landmark_abbr_list[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19"};
string landmarks_names[] = {"S", "N", "Or", "Po", "A", "B", "Pog", "Me", "Gn", "Go", "Ii", "Is", "Ul", "Ll", "Sn", "sPog", "ANS", "PNS", "Ar"};

float average_positions_x[] = {806.8866666666667, 1382.866666, 1269.22, 597.72, 1387.3066666666666, 1353.24, 1333.4733333333334, 1278.38, 1316.3133333333333, 719.8733333333333, 1412.62, 1430.8533333333332, 1552.56, 1527.06, 1494.2533333333333, 1419.56, 962.78, 1391.3333333333333, 669.3866666666667};
float average_positions_y[] = {1038.8, 973.4333333333333, 1224.16, 1215.0733333333333, 1534.4133333333334, 1842.0933333333332, 1988.12, 2046.04, 2028.3333333333333, 1724.2333333333333, 1700.1666666666667, 1706.8533333333332, 1622.4533333333334, 1809.3933333333334, 1499.9666666666667, 2045.6466666666668, 1428.7133333333334, 1445.1533333333334, 1314.0};

inline static Array<float>
predict_landmarks(Array input_image, vec3 size)
{
    Array<vec3> predictions_list;
    for (int i = 0; i < 19; i++)
    {

        // getting a segment
        vec3 crop_center = {average_positions_x[i], average_positions_y[i], 0.0f};
        vec3 min_corner = crop_center - (0.5 * size);
        vec3 max_corner = crop_center + (0.5 * size);
        min_corner = to_ivec3(min_corner);
        max_corner = to_ivec3(max_corner);

        Array segment = array_crop(input_image, min_corner, max_corner, mn::Allocator allocator = mn::allocator_top());

        // making model prediction on this segment
        // auto onnx_session = onnx_session_new(ONNX_MODEL_CEPHALOMETRIC_LANDMARK, mn::str_lit(LANDMARKS_STR[landmark]));
        vec3 prediction = model(segment);

        // remapping the predicted location from the segment to the original image
        vec3 final_prediction = prediction + min_corner;

        //adding each land mark to prediction list that contain all  pedicted landmarks locations
        predictions_list[i]=final_prediction
    }

    return predictions_list
}
