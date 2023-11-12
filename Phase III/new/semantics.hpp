#include "symbtab.hpp"

bool pred_brac_handle(int count_opencc,int count_closecc){
    if(count_opencc == count_closecc) return true;
return false;
}

bool valid_func_entry(string name,vector<par_records*> &new_par_list){
    // sort(new_par_list.begin(),new_par_list.end(),compare_par_records);
    for(int i=0; i < function_sym_table.size(); i++){
        //check for name
        if(function_sym_table[i]->name == name){
            //check for par-list (overloading.)
            vector<par_records*> curr_par_list = function_sym_table[i]->par_list;
            // sort(curr_par_list.begin(),curr_par_list.end(),compare_par_records);
            if(curr_par_list == new_par_list) return false;
        }   
    }
return true;
}

bool check_func_args(string name,vector<string> &func_args_list){ //fn name, types of fn_args.
    
    for(int i=0; i < function_sym_table.size(); i++){
        if(function_sym_table[i]->name == name){
            bool valid_fn = true;
            vector<par_records*> curr_par_list = function_sym_table[i]->par_list;

            for(int i=0;i<curr_par_list.size();i++){
                if(curr_par_list[i]->type != func_args_list[i]){
                    valid_fn = false;
                    break;
                }
            }
            if(valid_fn == true) return true;
        }
    }
return false;
}

bool std_lib_semantics (vector<string> ID2 = {}, string name,string ID1){

    //int_const,float_const,vec_const
    // note.  IN MISC LAST: vec_const can have ? as input arg.!!

    if(ID2.size() == 2){
        // collide function.
        bool rhs1;
        if(ID2[1] == "e" || ID2[1] == "int" ) rhs1 = true; // || ID2 == "int_const" 
        if(name == "collide" || ID1 == "mass" && ID2[1] == "mass" && rhs1){
            return true;
        }
        cout<<"ERROR in type check of Function args in collide!!"<<endl;
    return false;
    }else if(ID2.size() == 0){
        //GET R
        if(name == "getr" && ID1 == "mass"){
            return true;
        }
        // GET V
        else if(name == "getv" && ID1 == "mass"){
            return true;
        }

        //GET A
        else if(name == "geta" && ID1 == "mass"){
            return true;
        }

    return false;
    }else{
        //MAG

        if(name == "mag" && ID1 == "mass" && (ID2[0] == "velocity" || ID2[0] == "position" || ID2[0] == "acceleration" || ID2[0] == "momentum" || ID2[0] == "distance")){
            return true;
        }

        //SET_R ADD_R
        else if((name == "addr"|| name == "setr") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const")){
            return true;
        }

        //GET R
        else if((name == "addr"|| name == "setr") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const")){
            return true;
        }

        //R_AFTER.
        else if(name == "r_after" && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const")){
            return true;
        }

        //SET_V ADD_V
        else if((name == "setv" || name == "addv") && ID1 == "mass" && (ID2[0] == "velocity" || ID2[0] == "vec_const") ){
            return true;
        }

        //V_AFTER (time)
        else if((name == "v_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        //V_AFTER (distance)
        else if((name == "v_after") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const") ){
            return true;
        }

        //SET_A ADD_A
        else if((name == "seta" || name == "adda") && ID1 == "mass" && (ID2[0] == "acceleration" || ID2[0] == "vec_const")){
            return true;
        }

        // ENERGY KE,PE,TE
        else if((name == "ke_after" || name == "pe_after" || name == "te_after")  && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const")){
        return true;
        }

        //angle (time)
        else if((name == "angle_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        //angle (distance)
        else if((name == "angle_after") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const") ){
            return true;
        }

        //collision
        else if((name == "collide" || name == "time_to_collide") && ID1 == "mass" && ID2[0] == "mass"){
            return true;
        }

        // Misc Time:
        else if((name == "s_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        else if((name == "roc_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        else if((name == "p_after") && ID1 == "mass" && (ID2[0] == "time" || ID2[0] == "int" || ID2[0] == "int_const" || ID2[0] == "float" || ID2[0] == "float_const") ){
            return true;
        }

        //Misc time_to
         else if((name == "time_to_r") && ID1 == "mass" && (ID2[0] == "position" || ID2[0] == "vec_const")){
            return true;
        }

        else if((name == "time_to_v") && ID1 == "mass" && (ID2[0] == "velocity" || ID2[0] == "vec_const")){
            return true;
        }
    }


}