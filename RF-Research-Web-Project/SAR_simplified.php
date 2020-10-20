<?php
    session_start();
        // tracks user session
    include 'includes/header.php';
        // extends header file
    include "static/SAR_simplified_computation_handler.php";
        // extends computations handler file
?>
	<header>
    <link rel="stylesheet" type="text/css" href="includes/style.css">
		<link rel="stylesheet" type="text/css" href="static/css/simple-sidebar.css">
		<script src="https://cdnjs.cloudflare.com/ajax/libs/Chart.js/2.9.3/Chart.min.js" type="text/javascript"></script>
		<link rel="stylesheet" type="text/css" href="https://stackpath.bootstrapcdn.com/bootstrap/4.5.0/css/bootstrap.min.css">
    <style type="text/css">
      a.SAR_simplified_calc_tool-active{
        background-color: #ddd !important;
        text-decoration: underline 1px solid #222;
        color: #405580;
      }
      .btn{
        color: #fff !important;
      }
      form{
        background-color: #eeeeee !important;
        border: none;
        border-top: 2px solid #ccc;
      }
      h4{
        text-align: center;
      }
      h4.technology_ttl{
        font-size:20px;
        font-weight: bold;
        padding: 1%;
        text-decoration: underline;
      }
      span.inner-span{
        color: #537895 !important;
        font-weight: bold;
      }
      .age_set{
        width: 100%;
        margin-left: 4%;
      }
      .age_set ul{
        margin-left: 4%;
        display: block;
        margin: 1% 2%;
        padding: auto;
      }
      .age_set ul li{
        font-family: "Jost", sans-serif;
        font-size: 98.5% !important;
        font-weight: normal;
        color: #666;
        list-style: none;
        padding: 1% 2%;
      }
      input.gender_choice{
        background-color: rgb(184, 184, 148) !important;
        cursor: pointer;
      }
      p.properties_section_ttl{
        width: 100%;
        margin: 1% .2%;
        padding: 2% 2%;
        color: #f2f2f2 !important;
        background-color: #7f7f7f;
        font-family: sans-serif;
        font-size: 120%;
        font-weight: 500;
        overflow: hidden;
      }
      #age_en_hd_size_sctn,
      #sar_result_form,
      #age_sctn,
      #src_distance_form2,
      #src_distance_form1,
      #rf_source_form{
        display: none;
      }
      button.details-btn{
        float: right;
      }
      div .img-section{
        width: auto;
        margin: 2% 1%;
      }
      div .note-section{
        margin: 1% 2%;
      }
      h4.section-ttl{
        margin: 2% 1%;
        text-decoration: underline;
        color: #537895 !important;
      }
		</style>
	</header>
    			<div class="section-ttl">
    				<h2 class="h-title">Simplified SAR Calculator</h2>
          </div>
    			<div class="container">
                <div class="calc-tools-links">
                  <h4 class="technology_ttl">Important</h4>
                  <p><span class="special-term">Specific absorption rate <i>(SAR)</i></span> is a unit of measurement for the amount of radio frequency energy absorbed by the body when using
                    a wireless device or when exposed to electromagnetic radiations from the other radio signal sources. For approved 'healthy' levels of radio frequency energy by the
                    <span class="special-term">World Health Organization (WHO)</span> and <span class="special-term">International Telecommunications Union (ITU)</span>, the
                    maximum acceptable <span class="special-term">SAR</span> value is <span class="special-term">2[W/Kg]</span> i.e <span class="special-term">2 Watts</span> of energy per every
                     <span class="special-term">1 kilogram</span> of body mass.<br></p><br>
                </div>
                <div class="content-tools">
                  <div class="property_dfn_sctn">
                    <div class="dfn-section">
                      <h4 class="dfn-ttl">Short Guide</h4>
                      <a name="skin_ddepth"></a>
                      <p>The system provides a section on the right for <span class="special-term">SAR</span> properties definition.
                      The process is procedural using the control buttons provided allowing access to more properties that describes
                      different states favourable for precise SAR computation.<br>
                      <h4 class="section-ttl">Section 1</h4>
                      To begin, use the 1st initial window (as shown in <span class="special-terms">Fig 1</span> below) to select the <span class="special-term">Technology
                      </span>of your target RF source/device.<br>
                      <div class="img-section">
                        <img class="img-formula" src="static/imgs/SAR_calc_guide/SAR_calc_guide1.png"><br>
                        <span class="special-term"><b>Fig. 1: </b><i>Simplified SAR calculator guide</i></span>
                            <!-- SAR calc guide image1 -->
                      </div><br>
                      Using <span class="special-term">Next</span> button, proceed to RF-source and ageset definition window. <br>
                      <div class="sections-seperator">
                        <hr>
                          <span class="dot"></span>
                          <span class="dot"></span>
                          <span class="dot"></span>
                      </div><br>
                      <h4 class="section-ttl">Section 2</h4>
                      First, the immediate selection field in this section labelled <span class="special-term">RF Source</span> consists of a list of radio frequency (RF) sources/devices from which one is to select in relation to the technology type defined in section 1 above.
                      <div class="note-section">
                        <span class="special-terms">Note:</span><i style="color: #666;"> this selection must clearly match the technology in step 1 above</i>
                      </div>
                      Next, under <span class="special-terms">Ageset</span> selection field one is required to select the target for which the SAR analysis is to be carried on. This is followed by specifying the actual gender of the target ageset in <span special-terms>step 3.1,</span>. This
                      is as shown in <span special-terms>Fig. 2</span> below.
                     <div class="img-section">
                       <img class="img-formula" src="static/imgs/SAR_calc_guide/SAR_calc_guide2.png"><br>
                       <span class="special-term"><b>Fig. 2: </b><i>Simplified SAR calculator guide</i></span>
                           <!-- SAR calc guide image2 -->
                     </div><br>
                     Selecting <span class="special-term">Infant</span> as the target ageset will require defining <span class="special-term">age</span> which is to be in a range of <span class="special-term">[0 - 36]</span> months. Age is a fundamental factor in <span class="special-term">infant</span> ageset as its to be used in
                     determining the average head size of the target ageset.
                     <div class="note-section">
                        <span class="special-terms">Note:</span><i style="color: #666;"> age bracket is strict and entering a value off the range will be handled as an exception.</i>
                     </div>
                     Therefore, with <span class="special-term">Infant</span> as the ageset, <span class="special-term">Next</span> button opens a section with an entry field for age definition (<i>by default set to zero[0]</i>).
                    <div class="img-section">
                      <img class="img-formula" src="static/imgs/SAR_calc_guide/SAR_calc_guide3.png"><br>
                      <span class="special-term"><b>Fig. 3: </b><i>Simplified SAR calculator guide</i></span>
                          <!-- SAR calc guide image3 -->
                    </div><br>
                    <div class="sections-seperator">
                      <hr>
                        <span class="dot"></span>
                        <span class="dot"></span>
                        <span class="dot"></span>
                    </div><br>
                    <h4 class="section-ttl">Section 3</h4>
                    Defining ageset as <span class="special-term">Adult</span>, will require no <span class="special-term">age</span> definition as the calculator uses average adult human head sizes for <span class="special-term">male</span> and <span class="special-term">female</span> genders as default values.
                    The head sizes for both agesets are clearly displayed in <span class="special-terms">step 4</span> of the final properties definition window under <span class="special-term">Head size</span> field. They're captured by radius in units of <span class="special-term">centimeters [cm].</span><br>
                    Finally, in this section the user is to define the seperation distance between the radio frequency (RF) source or device in the analysis e.g mobile phone and target human ageset. Depending on selected RF-source/device, one is required to define the units of calibration for the seperation distance. For instance,
                    centimeters [cm] forms suitable units for mobile phones, bluetooth dongles among others. By default, this value is set to <span class="special-term">zero[0]</span>. Next, to complete properties definition the calculator provides a selection field for <span class="special-term">tissue type</span> which constitutes of
                     <span class="special-term">skin, fat, bone and brain</span>. These are the primary head tissues the whole analysis is all about and the general research as well in relation to RF radiation effects with <span class="special-term">Brain</span> being the center element. <br>Therefore, one is required to define a tissue
                     for which its <span class="special-term">specific absorption rate (SAR)</span> is to be computed.
                    <div class="img-section">
                      <img class="img-formula" src="static/imgs/SAR_calc_guide/SAR_calc_guide4.png"><br>
                      <span class="special-term"><b>Fig. 4: </b><i>Simplified SAR age definition window</i></span>
                          <!-- SAR calc guide image4 -->
                    </div><br>
                    <div class="sections-seperator">
                      <hr>
                        <span class="dot"></span>
                        <span class="dot"></span>
                        <span class="dot"></span>
                    </div><br>
                    <h4 class="section-ttl">Section 4</h4>
                    The calculation is accomplished by the <span class="special-term">Calculate</span> button which invokes the display of <i>result section.</i> This contains an SAR result display field with a result value defined in units of <span class="special-term">watts per kilogram[W/Kg]</span>. Alongside this SAR result value, there's
                    also a handy button labelled <span class="special-terms">More</span> which when clicked, invokes a small pop-up window with quite detailed information about the computed SAR analysis.
                   <div class="img-section">
                     <img class="img-formula" src="static/imgs/SAR_calc_guide/SAR_calc_guide5.png"><br>
                     <span class="special-term"><b>Fig. 5: </b><i>Simplified SAR result window</i></span>
                         <!-- SAR calc guide image5 -->
                   </div><br>
                   <div class="img-section">
                     <img class="img-formula" src="static/imgs/SAR_calc_guide/SAR_calc_guide6.png"><br>
                     <span class="special-term"><b>Fig. 6: </b><i>Simplified SAR calculation details</i></span>
                         <!-- SAR calc guide image6 -->
                   </div><br>
                    This forms the final step in SAR computation. <br>To perform new analysis, the <span class="special-term">Clear</span> button is provided to
                    clear and refresh the <i>properties definition</i> section.<br><br>
                    <div class="note-section">
                       <span class="special-terms">Note:</span><i style="color: #666;"> ALL the entry fields must the filled as required!</i>
                    </div>
                    </div>
                    <div class="calc-tool-section">
                      <form class="calc-tool-section" id="technology_form">
                        <br><p class="properties_section_ttl"><u>Properties Definition Section</u></span></p> <br><br>
                          <label class="rf-lalbels"><span class="special-terms">1.</span> Technology</label>
                          <select name="technology_type_option" id="technology_type_option" class="technology_type_option">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" value="Select" selected>Select</option>
                            <option class="label-input100" type="text" value="gsm1" >GSM 800/900</option>
                            <option class="label-input100" type="text" value="gsm2">GSM 1800/1900</option>
                            <option class="label-input100" type="text" value="2g">2G</option>
                            <option class="label-input100" type="text" value="3g">3G</option>
                            <option class="label-input100" type="text" value="4g">4G</option>
                            <option class="label-input100" type="text" value="5g">5G</option>
                            <option class="label-input100" type="text" value="wifi">WiFi</option>
                            <option class="label-input100" type="text" value="cellular">Cellular technology</option>
                            <option class="label-input100" type="text" value="bluetooth">Bluetooth</option>
                            <option class="label-input100" type="text" value="microwave">Microwave</option>
                            <option class="label-input100" type="text" value="satelite">Satellite</option>
                          </select><br><br>
                          <button class="btn calculate-btn nxt-btn" type="button" onclick="technology_form_hndlr();" name="technology_type_nxt_button">Next</button><br>
                          <div class="sections-seperator">
                            <hr>
                              <span class="dot"></span>
                              <span class="dot"></span>
                          </div>
                      </form>
                          <!-- ------Technology section------ -->

                      <form class="calc-tool-section" id="rf_source_form">
                          <br>
                          <label class="rf-lalbels"><span class="special-terms">2.</span> RF Source</label>
                          <select name="rf_source_type_option" id="rf_source_type_option" class="rf_source_type_option">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" id="" value="Select" selected>Select</option>
                            <option class="label-input100" type="text" id="phone" value="phone">Phone</option>
                            <option class="label-input100" type="text" id="gsm_module" value="gsm_module">GSM module</option>
                            <option class="label-input100" type="text" id="wifi_radio" value="wifi_radio">WiFi radio</option>
                            <option class="label-input100" type="text" id="bluetooth_dongle" value="bluetooth_dongle">Bluetooth dongle</option>
                            <option class="label-input100" type="text" id="microwave_oven" value="microwave_oven">Microwave oven</option>
                            <option class="label-input100" type="text" id="satelite_large" value="satelite_large">Satellite Large: 15-30 [m] diameter</option>
                            <option class="label-input100" type="text" id="satelite_medium" value="satelite_medium">Satellite Medium: 3-7 [m] diameter</option>
                            <option class="label-input100" type="text" id="satelite_small" value="satelite_small">Satellite Small: 0.5 - 2 [m] diameter</option>
                            <option class="label-input100" type="text" id="cellphone_tower" value="cellphone_tower">Cell phone signal booster tower</option>
                            <option class="label-input100" type="text" id="others" value="others">Others</option>
                          </select><br><br>
                          <label class="rf-lalbels"><span class="special-terms">3.</span> Ageset</label>
                          <select name="ageset_type_option" id="ageset_type_option" class="ageset_type_option2">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" value="infant" selected>Infant</option>
                            <option class="label-input100" type="text" value="adult">Adult</option>
                          </select><br><br>
                          <div class="age_set" id="age_set">
                            <label class="rf-lalbels"><span class="special-terms">3.1</span> Gender</label>
                            <ul>
                              <li><input class="gender_choice" type="radio" name="gender" value="male"><b>&nbsp;</b>Male</li>
                              <li><input class="gender_choice" type="radio" name="gender" value="female"><b>&nbsp;</b>Female</li>
                            </ul><br>
                            <button class="btn calculate-btn nxt-btn" type="button" onclick="rf_source_form_hndlr();" name="ageset_nxt_button1">Next</button><br>
                            <div class="age_en_hd_size_sctn" id="age_en_hd_size_sctn">
                              <div class="age_sctn" id="age_sctn">
                                  <div class="sections-seperator">
                                    <hr>
                                  </div><br><br>
                                    <label class="rf-lalbels"><span class="special-terms">3.2</span> Age(<span class="special-term">in months[0-36]</span>)</label>
                                    <input type="double" name="ageset_age_option" id="ageset_age_option" title="Set to 0 months by default" value="" placeholder="0">
                                    <br><br>
                                    <button class="btn calculate-btn nxt-btn" type="button" onclick="infant_age_hndlr();" name="ageset_nxt_button2">Next</button><br>
                              </div>
                                <div class="sections-seperator">
                                  <hr>
                                    <span class="dot"></span>
                                    <span class="dot"></span>
                                </div>
                            </div>
                          </div>
                      </form>
                          <!-- ------Ageset section------ -->

                      <form class="calc-tool-section" id="src_distance_form1">
                          <br>
                          <div class="age_sctn" id="hd_size_sctn">
                            <label class="rf-lalbels"><span class="special-terms">4.0</span> Head size (<span class="special-term">by radius</span>)</label><br>
                            <input type="text" name="ageset_hd_size_val" id="ageset_hd_size_val" value="" placeholder="">&nbsp;[<span class="special-term">cm</span>]
                            <br>
                            <div class="sections-seperator">
                              <hr>
                            </div><br>
                          </div>
                          <label class="rf-lalbels"><span class="special-terms">4.1</span> RF source distance</label><br>
                          <input class="rf_src_distance_option" id="rf_src_distance_option" type="double" name="rf_src_distance_option" title="Set to 0 by default" placeholder="0" required>
                          <select name="rf_src_distance_option" id="rf_src_distance_option_range" class="rf_src_distance_option">
                            <option class="input100" value=""></option>
                            <span class="focus-input100"></span>
                            <option class="label-input100" type="text" title="centimeters" value="cm" selected>cm</option>
                            <option class="label-input100" type="text" title="meters" value="m">m</option>
                            <option class="label-input100" type="text" title="kilometers" value="km">km</option>
                          </select><br><br>
                            <label class="rf-lalbels" style="margin-right: 2%;"><span class="special-terms">4.2</span> Tissue:</label>
                            <select name="tissue_type_option" id="tissue_type_option" class="tissue_type_option">
                              <option class="input100" value=""></option>
                              <span class="focus-input100"></span>
                              <option class="label-input100" type="text" value="Skin" selected>Skin</option>
                              <option class="label-input100" type="text" value="Fat">Fat</option>
                              <option class="label-input100" type="text" value="Bone">Bone</option>
                              <option class="label-input100" type="text" value="Brain">Brain</option>
                          </select><br><br><br>
                          <button class="btn calculate-btn nxt-btn" type="button" onclick="rf_source_distnc_hdlr();" name="rf_src_distance_nxt_button">Calculate</button><br>
                          <div class="sections-seperator">
                            <hr>
                              <span class="dot"></span>
                              <span class="dot"></span>
                          </div>
                      </form>
                          <!-- ------RF-source distance section1------ -->

                      <form class="calc-tool-section" id="sar_result_form">
                          <br>
                          <label class="rf-lalbels"><span class="special-terms">5.</span>SAR Result</label><br>
                          <input type="text" name="sar_result_val" id="sar_result_val" value="" placeholder="">&nbsp;[<span class="special-term">W/Kg</span>]
                          <br><br>
                          <button type="submit" class="btn sar_simplified_reset-btn" onclick="reset_properties_dfn_sctn();" name="reset_properties_sctn_button" title="clear & refresh section">Clear</button>
                          <button type="button" class="btn calculate-btn nxt-btn details-btn" onclick="compttn_details();" name="reset_properties_sctn_button" title="More SAR details">More</button><br><br>
                          <div class="sections-seperator">
                            <hr>
                              <span class="dot"></span>
                              <span class="dot"></span>
                          </div>
                      </form>
                          <!-- ------RF-source distance section2------ -->
                    </div>
                  </div>
                </div>
                           <!-- ---------controls toggling handler--------- -->
          </div>
        </div>
      </div>
  </div>

    <script>
       function toggle_rf_source_form(){
         document.getElementById("rf_source_form").style.display = "block";
       }
                // -----toggles rf_source_form into display----
       function toggle_src_distance_form1(){
         document.getElementById("src_distance_form1").style.display = "block";
       }
                // -----toggles src_distance_form1 into display----
       function toggle_src_distance_form2(){
         document.getElementById("src_distance_form2").style.display = "block";
       }
                // -----toggles src_distance_form2 into display----
       function toggle_sar_result_form(){
         document.getElementById("sar_result_form").style.display = "block";
       }
                // -----toggles sar_result_form into display----
       function toggle_age_sctn(){
         document.getElementById("age_en_hd_size_sctn").style.display = "block";
         document.getElementById("age_sctn").style.display = "block";
       }
                // -----toggles age section into display----
       function rf_sorc_slctr(){
          if (technology_type_optn==="gsm1" || technology_type_optn==="gsm2") {
            document.getElementById("phone").style.display = "none";
            document.getElementById("wifi_radio").style.display = "none";
            document.getElementById("bluetooth_dongle").style.display = "none";
            document.getElementById("microwave_oven").style.display = "none";
            document.getElementById("satelite_large").style.display = "none";
            document.getElementById("satelite_medium").style.display = "none";
            document.getElementById("satelite_small").style.display = "none";
            document.getElementById("cellphone_tower").style.display = "none";
          }
          if (technology_type_optn==="wifi") {
            document.getElementById("phone").style.display = "none";
            document.getElementById("gsm_module").style.display = "none";
            document.getElementById("bluetooth_dongle").style.display = "none";
            document.getElementById("microwave_oven").style.display = "none";
            document.getElementById("satelite_large").style.display = "none";
            document.getElementById("satelite_medium").style.display = "none";
            document.getElementById("satelite_small").style.display = "none";
            document.getElementById("cellphone_tower").style.display = "none";
          }
          if (technology_type_optn==="cellular") {
            document.getElementById("phone").style.display = "none";
            document.getElementById("wifi_radio").style.display = "none";
            document.getElementById("bluetooth_dongle").style.display = "none";
            document.getElementById("microwave_oven").style.display = "none";
            document.getElementById("satelite_large").style.display = "none";
            document.getElementById("satelite_medium").style.display = "none";
            document.getElementById("satelite_small").style.display = "none";
            document.getElementById("gsm_module").style.display = "none";
          }
          if (technology_type_optn==="bluetooth") {
            document.getElementById("phone").style.display = "none";
            document.getElementById("wifi_radio").style.display = "none";
            document.getElementById("gsm_module").style.display = "none";
            document.getElementById("microwave_oven").style.display = "none";
            document.getElementById("satelite_large").style.display = "none";
            document.getElementById("satelite_medium").style.display = "none";
            document.getElementById("satelite_small").style.display = "none";
            document.getElementById("cellphone_tower").style.display = "none";
          }
          if (technology_type_optn==="microwave") {
            document.getElementById("phone").style.display = "none";
            document.getElementById("wifi_radio").style.display = "none";
            document.getElementById("bluetooth_dongle").style.display = "none";
            document.getElementById("gsm_module").style.display = "none";
            document.getElementById("satelite_large").style.display = "none";
            document.getElementById("satelite_medium").style.display = "none";
            document.getElementById("satelite_small").style.display = "none";
            document.getElementById("cellphone_tower").style.display = "none";
          }
          if (technology_type_optn==="satelite") {
            document.getElementById("phone").style.display = "none";
            document.getElementById("wifi_radio").style.display = "none";
            document.getElementById("bluetooth_dongle").style.display = "none";
            document.getElementById("microwave_oven").style.display = "none";
            document.getElementById("gsm_module").style.display = "none";
            document.getElementById("cellphone_tower").style.display = "none";
          }
          if ((technology_type_optn==="2g") || (technology_type_optn==="3g") || (technology_type_optn==="4g") || technology_type_optn==="5g") {
            document.getElementById("gsm_module").style.display = "none";
            document.getElementById("wifi_radio").style.display = "none";
            document.getElementById("bluetooth_dongle").style.display = "none";
            document.getElementById("gsm_module").style.display = "none";
            document.getElementById("satelite_large").style.display = "none";
            document.getElementById("satelite_medium").style.display = "none";
            document.getElementById("satelite_small").style.display = "none";
            document.getElementById("cellphone_tower").style.display = "none";
          }
        }
                // selects rf-device w.r.t technology

       var error_flag,
          rf_source_optn,
          ageSet_optn,
          gender_optn,
          ageset_age_option,
          ageset_age_val,
          gender_optn_select,
          infant_age,
          head_siz,
          age_brckt_optn,
          rf_source_dstnce,
          tissue_type,
          sar_result_info,
          rf_source_dstnce_range,
          technology_type_optn;
          <?php
            global $gender_optn, $age_brckt_optn_id;
           ?>
          error_flag ='OFF';
              // process track flag set LOW by default
              // keep track of processes states

          var pi = Math.PI;
                  // pi value

       function technology_fns_selector(){
         var technology;
         if(technology_type_optn==="gsm1") {
           technology = "GSM 800/900 technology";
           rf_src_dvc = "";
           if(rf_source_optn==="gsm_module" || rf_source_optn==="others") {
             gsm_module1_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match to "+technology+".\nPlease make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //GSM 800/900 technology handler fn
         if(technology_type_optn==="gsm2") {
           technology = "GSM 1800/1900 technology";
           if(rf_source_optn==="gsm_module" || rf_source_optn==="others" ) {
             gsm_module2_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //GSM 1800/1900 technology handler fn
         if(technology_type_optn==="wifi") {
           technology = "WiFi technology";
           if(rf_source_optn==="wifi_radio" || rf_source_optn==="others" ) {
             wifi_radio_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //WIFI technology handler fn
         if(technology_type_optn==="cellular") {
           technology = "Cellular technology";
           if(rf_source_optn==="cellphone_tower" || rf_source_optn==="others") {
             cellphone_tower_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //Cellphone tower technology handler fn
         if(technology_type_optn==="2g") {
           technology = "2G technology";
           if(rf_source_optn==="phone" || rf_source_optn==="others") {
             ntwrk_2G_tchnlgy_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //2G technology handler fn
         if(technology_type_optn==="3g") {
           technology = "3G technology";
           if(rf_source_optn==="phone" || rf_source_optn==="others") {
             ntwrk_3G_tchnlgy_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //3G technology handler fn
         if(technology_type_optn==="4g") {
           technology = "4G technology";
           if(rf_source_optn==="phone" || rf_source_optn==="others") {
             ntwrk_4G_tchnlgy_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //4G technology handler fn
         if(technology_type_optn==="5g") {
           technology = "5G technology";
           if(rf_source_optn==="phone" || rf_source_optn==="others") {
             ntwrk_5G_tchnlgy_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //5G technology handler fn
         if(technology_type_optn==="bluetooth") {
           technology = "Bluetooth technology";
           if(rf_source_optn==="bluetooth_dongle" || rf_source_optn==="others") {
             bltth_dngl_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //Bluetooth technology handler fn
         if(technology_type_optn==="microwave") {
           technology = "Microwave technology";
           if(rf_source_optn==="microwave_oven" || rf_source_optn==="others") {
             mw_oven_hndlr();
           }
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
                 //Microwave technology handler fn
         if(technology_type_optn==="satelite") {
           technology = "Satellite technology";
           if(rf_source_optn==="satelite_large" || rf_source_optn==="others") {
             satellite_large_hndlr();
           }
                   //Satellite(large) technology handler fn
           else if(rf_source_optn==="satelite_medium" || rf_source_optn==="others") {
             satellite_medium_hndlr();
           }
                   //Satellite(medium) technology handler fn
           else if(rf_source_optn==="satelite_small" || rf_source_optn==="others") {
             satellite_small_hndlr();
           }
                   //Satellite(small) technology handler fn
           else {
             alert("Exception detected!\nIncompatible match. to "+technology+".\n Please make a new selection for RF-device(If not in the list, select 'Others')");
           }
         }
        }

       function technology_form_hndlr(){
          var selected_technology_optn = technology_form.elements['technology_type_option'].selectedIndex;
                  // checks selected technology
          technology_type_optn = technology_form.elements['technology_type_option'].options[selected_technology_optn].value;
                // fetch actual technology option selected
          if(selected_technology_optn > 0 && technology_type_optn != "Select"){
            // rf_sorc_slctr();
                  // calls rf-device source fn
            toggle_rf_source_form();
                  // calls fn to toggle RF source form
          }
          else{
            alert("Exception detected!\nNo technology type selected.");
          }
          }
                    // technology section handler fn
          function ageset_hndlr(){
          var ageset_gender = document.getElementsByName('gender');
          console.log(ageset_gender);
          ageset_gender.forEach(e => {
              if (e.checked) {
                  //if radio button is checked, set sort style
                  gender_optn = e.value;
                  if (gender_optn === "male") {

                    gender_optn_select = "male";
                    <?php $gender_optn = "male"; ?>
                  }
                  if (gender_optn === "female") {

                    gender_optn_select = "female";
                    <?php $gender_optn = "female"; ?>
                  }
                  // php vars to track gender
              }
          });
                // grabs gender value from checked radio button
        }

       function rf_source_form_hndlr(){
          var selected_rf_source_optn = rf_source_form.elements['rf_source_type_option'].selectedIndex;
          var selected_ageSet_optn = rf_source_form.elements['ageset_type_option'].selectedIndex;
                // checks user selected options
          rf_source_optn = rf_source_form.elements['rf_source_type_option'].options[selected_rf_source_optn].value;
                // fetch actual user values from options
          technology_fns_selector();
                // fn verifies technology and rf-source selected
          ageset_hndlr();
            // gender handler fn
          if (selected_rf_source_optn > 0 && selected_ageSet_optn > 0 && (gender_optn === 'male' || gender_optn === 'female') && rf_source_optn != "Select") {
            ageSet_optn = rf_source_form.elements['ageset_type_option'].options[selected_ageSet_optn].value;
            if (ageSet_optn === 'adult') {
              head_siz_set_hndlr();
                        // prints head size
              toggle_src_distance_form1();
               document.getElementById("age_sctn").style.display = "none";
            }
                  // calls fn to toggle head size sestion
            else if(ageSet_optn === 'infant'){
              toggle_age_sctn();
                    // calls fn to toggle age sestion
            }
          }
        else if (rf_source_optn === "Select") {
          alert("Exception detected!\nRF Source, Ageset and Gender options are all required.");
        }
        else {
          alert("Exception detected!\nRF Source, Ageset and Gender options are all required.");
        }
      }
       function infant_age_hndlr(){
        ageset_age_option = document.getElementById('ageset_age_option').value;
        if ((ageset_age_option >= 0) && (ageset_age_option <= 36)) {
                  // alert(ageset_age_option);
          toggle_src_distance_form1();
                  // calls section 4 invoke fn
          head_siz_set_hndlr();
                  // handles head size for the agesets
        }
        else {
          alert("Exception detected!\nInfant age value is required(MUST be between 0 - 36).");
        }
      }
       function head_siz_hndlr(){
          ageset_hndlr();
            // gender handler fn
          ageset_age_option = document.getElementById('ageset_age_option').value;
            // grabs age option
          var head_siz_val = document.getElementById("ageset_hd_size_val");
          if (ageset_age_option ==="") {
            if (gender_optn_select === "female") {
              ageset_age_val = 32.759490;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 33.083890;
            }
          }
          if (ageset_age_option >= 0.0 && ageset_age_option < 0.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 32.759490;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 33.083890;
            }
          }
          if (ageset_age_option > 0.0 && ageset_age_option <= 0.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 34.173460;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 34.672530;
            }
          }
          if (ageset_age_option > 0.5 && ageset_age_option <= 1.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 36.233260;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 36.973770;
            }
          }
          if (ageset_age_option > 1.5 && ageset_age_option <= 2.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 37.706850;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 38.607240;
            }
          }
          if (ageset_age_option > 2.5 && ageset_age_option <= 3.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 38.838140;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 39.851230;
            }
          }
          if (ageset_age_option > 3.5 && ageset_age_option <= 4.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 39.745880;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 40.841140;
            }
          }
          if (ageset_age_option > 4.5 && ageset_age_option <= 5.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 40.496720;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 41.652910;
            }
          }
          if (ageset_age_option > 5.5 && ageset_age_option <= 6.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 41.131710;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 42.333300;
            }
          }
          if (ageset_age_option > 6.5 && ageset_age_option <= 7.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 41.677870;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 42.913110;
            }
          }
          if (ageset_age_option > 7.5 && ageset_age_option <= 8.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 42.153910;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 43.413650;
            }
          }
          if (ageset_age_option > 8.5 && ageset_age_option <= 9.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 42.573300;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 43.850250;
            }
          }
          if (ageset_age_option > 9.5 && ageset_age_option <= 10.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 42.946040;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 44.234320;
            }
          }
          if (ageset_age_option > 10.5 && ageset_age_option <= 11.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 43.279770;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 44.574540;
            }
          }
          if (ageset_age_option > 11.5 && ageset_age_option <= 12.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 43.580430;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 44.877670;
            }
          }
          if (ageset_age_option > 12.5 && ageset_age_option <= 13.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 43.852740;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 45.149080;
            }
          }
          if (ageset_age_option > 13.5 && ageset_age_option <= 14.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 44.100500;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 45.393100;
            }
          }
          if (ageset_age_option > 14.5 && ageset_age_option <= 15.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 44.326820;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 45.613250;
            }
          }
          if (ageset_age_option > 15.5 && ageset_age_option <= 16.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 44.534280;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 45.812450;
            }
          }
          if (ageset_age_option > 16.5 && ageset_age_option <= 17.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 44.725010;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 45.993150;
            }
          }
          if (ageset_age_option > 17.5 && ageset_age_option <= 18.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 44.900850;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.157390;
            }
          }
          if (ageset_age_option > 18.5 && ageset_age_option <= 19.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.063330;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.306920;
            }
          }
          if (ageset_age_option > 19.5 && ageset_age_option <= 20.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.213780;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.443250;
            }
          }
          if (ageset_age_option > 20.5 && ageset_age_option <= 21.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.353340;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.567670;
            }
          }
          if (ageset_age_option > 21.5 && ageset_age_option <= 22.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.483010;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.681290;
            }
          }
          if (ageset_age_option > 22.5 && ageset_age_option <= 23.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.603670;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.785110;
            }
          }
          if (ageset_age_option > 23.5 && ageset_age_option <= 24.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.716080;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.879970;
            }
          }
          if (ageset_age_option > 24.5 && ageset_age_option <= 25.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.820920;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 46.966630;
            }
          }
          if (ageset_age_option > 25.5 && ageset_age_option <= 26.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 45.918780;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.045780;
            }
          }
          if (ageset_age_option > 26.5 && ageset_age_option <= 27.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.010210;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.118010;
            }
          }
          if (ageset_age_option > 27.5 && ageset_age_option <= 28.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.095680;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.183850;
            }
          }
          if (ageset_age_option > 28.5 && ageset_age_option <= 29.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.175620;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.243790;
            }
          }
          if (ageset_age_option > 29.5 && ageset_age_option <= 30.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.250430;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.298240;
            }
          }
          if (ageset_age_option > 30.5 && ageset_age_option <= 31.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.320440;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.347610;
            }
          }
          if (ageset_age_option > 31.5 && ageset_age_option <= 32.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.385990;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.392250;
            }
          }
          if (ageset_age_option > 32.5 && ageset_age_option <= 33.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.447360;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.432470;
            }
          }
          if (ageset_age_option >= 33.5 && ageset_age_option < 34.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.504810;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.468570;
            }
          }
          if (ageset_age_option > 34.5 && ageset_age_option <= 35.5) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.558590;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.500810;
            }
          }
          if (ageset_age_option > 35.5 && ageset_age_option <= 36) {
            if (gender_optn_select === "female") {
              ageset_age_val = 46.584170;
            }
            if (gender_optn_select === "male") {
              ageset_age_val = 47.515560;
            }
          }
            // use infant age to determine head size

          head_siz = ageset_age_val / (2*pi);
              // converts the fetched value to radius
          head_siz_val.value = head_siz.toFixed(4);
              // formats result to 4 d.p
          head_siz /= 100;
              // converts to units of 'm'
      }
       function head_siz_set_hndlr(){
        var head_siz_val = document.getElementById("ageset_hd_size_val");
                // rf-source distance conversion
        if (ageSet_optn === 'adult') {
          if (gender_optn === "male") {
            head_siz = 9.310564;
              // average adult male head radius
            head_siz_val.value = head_siz.toFixed(4);
              // sets head size
          }
          if (gender_optn === "female") {
            head_siz = 8.892888;
              // average adult female head radius
            head_siz_val.value = head_siz.toFixed(4);
              // sets head size
          }
        }
        if (ageSet_optn === 'infant') {
          toggle_age_sctn();
                // calls fn to toggle age sestion
          head_siz_hndlr();
                // calls fn to handle head size
        }
      }
       function rf_source_distnc_hdlr(){
        head_siz_set_hndlr();
                // calls head size handler fn
        var selected_rf_source_dstnce_range = src_distance_form1.elements['rf_src_distance_option_range'].selectedIndex;
                // checks selected source distance range
        var selected_tissue_type_option = src_distance_form1.elements['tissue_type_option'].selectedIndex;
                // determine tissue type
        rf_source_dstnce = document.getElementById('rf_src_distance_option').value;
        if (rf_source_dstnce >= 0 && selected_rf_source_dstnce_range > 0 && selected_tissue_type_option > 0) {
          rf_source_dstnce_range = src_distance_form1.elements['rf_src_distance_option_range'].options[selected_rf_source_dstnce_range].value;
          tissue_type = src_distance_form1.elements['tissue_type_option'].options[selected_tissue_type_option].value;
                // fetch selected source distance range value and tissue type
          if (rf_source_dstnce_range === "cm") {
            rf_source_dstnce *= 0.01;
          }
          else if(rf_source_dstnce_range === "m"){
            rf_source_dstnce *= 1;
          }
          else if(rf_source_dstnce_range === "km"){
            rf_source_dstnce *= 1000;
          }
          toggle_sar_result_form();
                  // calls SAR computation fn

          // -----------control fns selection-------------------------
          technology_fns_selector();
          // -----------control fns selection-------------------------

          var tissue_sar_result = document.getElementById("sar_result_val");
          tissue_sar_result.value = sar_val.toFixed(6);
            // passes SAR result to display field
        }
        else {
          alert("Exception detected!\nRF source distance value, units range and tissue type are all required.");
        }
      }
      function compttn_details(){
        var technology, rf_src;
        if (technology_type_optn === "gsm1") {
          technology = "GSM 800/900";
        }
        if (technology_type_optn === "gsm2") {
          technology = "GSM 1800/1900";
        }
        if (technology_type_optn === "2g") {
          technology = "2G";
        }
        if (technology_type_optn === "3g") {
          technology = "3G";
        }
        if (technology_type_optn === "4g") {
          technology = "4G";
        }
        if (technology_type_optn === "5g") {
          technology = "5G";
        }
        if (technology_type_optn === "wifi") {
          technology = "WiFi";
        }
        if (technology_type_optn === "cellular") {
          technology = "Cellular tower";
        }
        if (technology_type_optn === "bluetooth") {
          technology = "Bluetooth";
        }
        if (technology_type_optn === "microwave") {
          technology = "Microwave";
        }
        if (technology_type_optn === "satelite") {
          technology = "Satellite";
        }
        // --------------technologies--------------------

        if (rf_source_optn === "gsm_module") {
          rf_src = "GSM Module";
        }
        if (rf_source_optn === "phone") {
          rf_src = "Phone";
        }
        if (rf_source_optn === "wifi_radio") {
          rf_src = "WiFi Radio";
        }
        if (rf_source_optn === "cellphone_tower") {
          rf_src = "Cellphone Tower";
        }
        if (rf_source_optn === "bluetooth_dongle") {
          rf_src = "Bluetooth Dongle";
        }
        if (rf_source_optn === "microwave_oven") {
          rf_src = "Microwave oven";
        }
        if (rf_source_optn === "satelite_small") {
          rf_src = "Satellite Small: 0.5 - 2 [m] diameter";
        }
        if (rf_source_optn === "satelite_medium") {
          rf_src = "Satellite Medium: 3-7 [m] diameter";
        }
        if (rf_source_optn === "satelite_large") {
          rf_src = "Satellite Large: 15-30 [m] diameter";
        }
        if (rf_source_optn === "others") {
          rf_src = "Others";
        }
        // --------------rf-device source--------------------

        alert("Computation Summary\n--------------------------------\n\n1. TECHNOLOGY - "+ technology +"\n2. RF-SOURCE - "+ rf_src +"\n3. TISSUE - "+ tissue_type +"\n\n-Impedance: "+ tissue_impdnc.toFixed(4)+"\n-Skin depth: "+ skin_dpth.toFixed(4)+ "\n-Power density: "+ pwr_dnsty.toFixed(4)+"\n-E-filed: "+ e_field.toFixed(4)+ "\n-SAR: "+ sar_val.toFixed(6));
      }
            // displays computed info
      function reset_properties_dfn_sctn(){
        document.getElementById('rf_source_form').reset();
        document.getElementById('src_distance_form1').reset();
        document.getElementById('src_distance_form2').reset();
        document.getElementById('sar_result_form').reset();
              // reset forms
        document.getElementById("age_en_hd_size_sctn").style.display = "none";
        document.getElementById("sar_result_form").style.display = "none";
        document.getElementById("src_distance_form2").style.display = "none";
        document.getElementById("src_distance_form1").style.display = "none";
        document.getElementById("rf_source_form").style.display = "none";
              // toggles display OFF for the sections
      }
    </script>
    <script>
					//navbar script handler
			$("#menu-toggle").click(function(e) {
			e.preventDefault();
			$("#wrapper").toggleClass("toggled");
			});
    </script>
    <!-- /#wrapper -->
  <!-- footer -->
  <?php
    include 'includes/footer.php'
  ?>
</body>

</html>
