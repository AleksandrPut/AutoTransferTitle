
#include <stdio.h>
#include <uf.h>
#include <uf_ui.h>
#include <uf_defs.h>
#include <uf_drf.h>
#include <uf_curve.h>
#include <uf_assem.h>
#include <uf_param.h>
#include <uf_tabnot.h>

#include <uf_view.h>
#include <uf_draw.h>
#include <uf_obj.h>
#include <uf_modl.h>


#include <iostream>
#include <string>
#include <vector>



#include <uf_defs.h>
#include <NXOpen/NXException.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/Annotations_AnnotationManager.hxx>
#include <NXOpen/Annotations_AssociativeText.hxx>
#include <NXOpen/Annotations_BaseTitleBlockBuilder.hxx>
#include <NXOpen/Annotations_DefineTitleBlockBuilder.hxx>
#include <NXOpen/Annotations_SelectTableSectionList.hxx>
#include <NXOpen/Annotations_TableSection.hxx>
#include <NXOpen/Annotations_TitleBlock.hxx>
#include <NXOpen/Annotations_TitleBlockCellBuilder.hxx>
#include <NXOpen/Annotations_TitleBlockCellBuilderList.hxx>
#include <NXOpen/Annotations_TitleBlockCollection.hxx>
#include <NXOpen/AttributeManager.hxx>
#include <NXOpen/AttributePropertiesBaseBuilder.hxx>
#include <NXOpen/AttributePropertiesBuilder.hxx>
#include <NXOpen/BasePart.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/DateBuilder.hxx>
#include <NXOpen/DateItemBuilder.hxx>
#include <NXOpen/DateItemBuilderList.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Drafting_DraftingApplicationManager.hxx>
#include <NXOpen/Expression.hxx>
#include <NXOpen/MassPropertiesBuilder.hxx>
#include <NXOpen/MenuBar_ContextMenu.hxx>
#include <NXOpen/MenuBar_ContextMenuEntry.hxx>
#include <NXOpen/MenuBar_ContextMenuProperties.hxx>
#include <NXOpen/MenuBar_MenuBarManager.hxx>
#include <NXOpen/MenuBar_MenuButton.hxx>
#include <NXOpen/NXObject.hxx>
#include <NXOpen/ObjectList.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/PreviewPropertiesBuilder.hxx>
#include <NXOpen/PropertiesManager.hxx>
#include <NXOpen/SelectNXObjectList.hxx>
#include <NXOpen/SelectObjectList.hxx>
#include <NXOpen/Selection.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/Update.hxx>
#include <NXOpen/Annotations_TitleBlockCellBuilder.hxx>


#include <uf_defs.h>
#include <NXOpen/NXException.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/Annotations_BaseTitleBlockBuilder.hxx>
#include <NXOpen/Annotations_EditTitleBlockBuilder.hxx>
#include <NXOpen/Annotations_TitleBlock.hxx>
#include <NXOpen/Annotations_TitleBlockCellBuilder.hxx>
#include <NXOpen/Annotations_TitleBlockCellBuilderList.hxx>
#include <NXOpen/Annotations_TitleBlockCollection.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Drafting_DraftingApplicationManager.hxx>
#include <NXOpen/MenuBar_ContextMenuProperties.hxx>
#include <NXOpen/NXObject.hxx>
#include <NXOpen/ObjectList.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/Selection.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/TaggedObject.hxx>
#include <NXOpen/UserDefinedObjects_UserDefinedDisplayEvent.hxx>
#include <NXOpen/UserDefinedObjects_UserDefinedEvent.hxx>
#include <NXOpen/UserDefinedObjects_UserDefinedObject.hxx>
#include <NXOpen/UserDefinedObjects_UserDefinedObjectDisplayContext.hxx>

#include <NXOpen/NXException.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/Annotations_BendTableSettingsBuilder.hxx>
#include <NXOpen/Annotations_BillOfMaterialBuilder.hxx>
#include <NXOpen/Annotations_CutSheetBuilder.hxx>
#include <NXOpen/Annotations_HoleTableSettingsContentBuilder.hxx>
#include <NXOpen/Annotations_HoleTableSettingsFormatBuilder.hxx>
#include <NXOpen/Annotations_HoleTableSettingsHoleFiltersBuilder.hxx>
#include <NXOpen/Annotations_HoleTableSettingsLabelBuilder.hxx>
#include <NXOpen/Annotations_HoleTableSettingsWorkflowBuilder.hxx>
#include <NXOpen/Annotations_LetteringStyleBuilder.hxx>
#include <NXOpen/Annotations_LineArrowStyleBuilder.hxx>
#include <NXOpen/Annotations_OrdinateStyleBuilder.hxx>
#include <NXOpen/Annotations_PartsListBuilder.hxx>
#include <NXOpen/Annotations_PinListBuilder.hxx>
#include <NXOpen/Annotations_TableCellStyleBuilder.hxx>
#include <NXOpen/Annotations_TableColumnBuilder.hxx>
#include <NXOpen/Annotations_TableEditSettingsBuilder.hxx>
#include <NXOpen/Annotations_TableSectionStyleBuilder.hxx>
#include <NXOpen/Annotations_TabularNoteStyleBuilder.hxx>
#include <NXOpen/Builder.hxx>
#include <NXOpen/DisplayableObject.hxx>
#include <NXOpen/Drafting_BaseEditSettingsBuilder.hxx>
#include <NXOpen/Drafting_SettingsManager.hxx>
#include <NXOpen/Part.hxx>
#include <NXOpen/PartCollection.hxx>
#include <NXOpen/Session.hxx>
#include <NXOpen/DraftingManager.hxx>
#include <NXOpen/Drawings_SectionLineCollection.hxx>

#include <NXOpen/NXObjectManager.hxx>

using namespace NXOpen;

#include <NXSigningResource.cpp>
#include <exception>


#define UF_CALL(X) (report( __FILE__, __LINE__, #X, (X)))

int report(const char* file, int line, const char* call, int irc)
{
    if (irc)
    {
        char    messg[133];
        printf("%s, line %d:  %s\n", file, line, call);
        (UF_get_fail_message(irc, messg)) ?
            printf("    returned a %d\n", irc) :
            printf("    returned error %d:  %s\n", irc, messg);
        if (!UF_UI_open_listing_window())
        {
            UF_UI_write_listing_window(messg);
            UF_UI_write_listing_window("\n");
            UF_UI_write_listing_window(call);
            UF_UI_write_listing_window(";\n");
        }
    }
    return(irc);
}

void rename_title()
{
    UF_UI_open_listing_window();
    //int irc = 0;
    //if (irc) throw UF_CALL(__FILE__, __LINE__, irc);

    tag_t part = UF_ASSEM_ask_work_part();

    NXOpen::Session* theSession = NXOpen::Session::GetSession();
    NXOpen::Part* workPart(theSession->Parts()->Work());
    NXOpen::Part* displayPart(theSession->Parts()->Display());
    // ----------------------------------------------
    //   Menu: Изменить->Таблица->Настройки
    // ----------------------------------------------
    /*int num_drawings;
    tag_p_t drawing_tags;
    //Находим все листы чертежа
    UF_CALL(UF_DRAW_ask_drawings(&num_drawings, &drawing_tags));
    for (int i = 0; i < num_drawings; ++i) 
    {

    }

    tag_t finded_table;
    UF_OBJ_cycle_by_name("Sheet 1@0", &finded_table);
    UF_UI_write_listing_window(("finded_table - " + std::to_string(finded_table)).c_str());
    UF_UI_write_listing_window("\n");*/
    //if (irc) throw ug_err(THIS_FILE, __LINE__, irc);
    /*
   std::vector<NXOpen::DisplayableObject*> objects1(1);
    //NXOpen::DisplayableObject* displayableObject1(dynamic_cast<NXOpen::DisplayableObject*>(workPart->FindObject("ENTITY 218 15 1")));
    NXOpen::DisplayableObject* displayableObject1(dynamic_cast<NXOpen::DisplayableObject*>(workPart->FindObject("HANDLE R-2225")));

    std::vector<NXOpen::NXObject::AttributeInformation> GetAttributeTitlesByType = displayableObject1->GetAttributeTitlesByType(NXOpen::NXObject::AttributeType::AttributeTypeAny);
    for (int i = 0; i < GetAttributeTitlesByType.size(); i++)
    {
        UF_UI_write_listing_window(("#1 - " + (std::string)GetAttributeTitlesByType[i].StringValue.GetLocaleText()).c_str());
        UF_UI_write_listing_window("\n");
        UF_UI_write_listing_window(("#2 - " + (std::string)GetAttributeTitlesByType[i].ReferenceValue.GetLocaleText()).c_str());
        UF_UI_write_listing_window("\n");

    }


    objects1[0] = displayableObject1;
    NXOpen::Annotations::TableEditSettingsBuilder* tableEditSettingsBuilder1;
    tableEditSettingsBuilder1 = workPart->SettingsManager()->CreateTableEditSettingsBuilder(objects1);

    char name[200];
    UF_OBJ_ask_name(objects1[0]->Tag(), name);
    UF_UI_write_listing_window(("name - " + (std::string)name).c_str());
    UF_UI_write_listing_window("\n");


    objects1[0] = displayableObject1;

    //char *cell_text[200];
    //UF_TABNOT_ask_cell_text(objects1[0]->Tag(), cell_text);
    //UF_UI_write_listing_window(("cell_text - " + (std::string)*cell_text).c_str());
    //UF_UI_write_listing_window("\n");

    UF_TABNOT_cell_prefs_t cell_prefs;
    // Получить настройки ячейки ячейки
    UF_TABNOT_ask_cell_prefs(objects1[0]->Tag(), &cell_prefs);

    UF_UI_write_listing_window(("url - " + (std::string)cell_prefs.url).c_str());
    UF_UI_write_listing_window("\n");
    UF_UI_write_listing_window(("ss_row - " + std::to_string(cell_prefs.ss_row)).c_str());
    UF_UI_write_listing_window("\n");
    UF_UI_write_listing_window(("ss_col - " + std::to_string(cell_prefs.ss_col)).c_str());
    UF_UI_write_listing_window("\n");
    UF_UI_write_listing_window(("ss_sheet - " + std::to_string(cell_prefs.ss_sheet)).c_str());
    UF_UI_write_listing_window("\n");


    //UF_TABNOT_set_cell_text(objects1[0]->Tag(), "<WID149*0@FILENAME>ыаваывавввввввввввввввв\nввввввввввввввввввввввввas\nвввввввввввввввввввввв");
   
    //UF_TABNOT_set_row_height(objects1[0]->Tag(), 2.0);


    /*std::vector<NXOpen::Drafting::BaseEditSettingsBuilder*> editsettingsbuilders1(1);
    editsettingsbuilders1[0] = tableEditSettingsBuilder1;
    workPart->SettingsManager()->ProcessForMultipleObjectsSettings(editsettingsbuilders1);
    tableEditSettingsBuilder1->TableLettering()->SetGeneralTextSize(2.0);
    //tableEditSettingsBuilder1->TableLettering()->SetSymbolFontFile("<WRef1 * 0@FILENAME>dfsdfsfsdfsd");
    NXOpen::NXObject* nXObject1;
    nXObject1 = tableEditSettingsBuilder1->Commit();
    tableEditSettingsBuilder1->Destroy();*/
    //cell_text[0] = const_cast<char*>("<WRef1 * 0@FILENAME>ыаваывавввввввввввввввв\nввввввввввввввввввввввввas\nвввввввввввввввввввввв");
    //UF_free(cell_text);
    //UF_UI_write_listing_window(("displayableObject1 - " + std::to_string(objects1[0]->Tag())).c_str());
    //UF_UI_write_listing_window("\n");
    /* int type1;
    int subtype1;
    UF_OBJ_ask_type_and_subtype(objects1[0]->Tag(), &type1, &subtype1);//UF_parametric_text_type    UF_tabular_note_cell_subtype
    UF_UI_write_listing_window(("type1 - " + std::to_string(type1)).c_str());
    UF_UI_write_listing_window("\n");
    
    UF_UI_write_listing_window(("subtype1 - " + std::to_string(subtype1)).c_str());
    UF_UI_write_listing_window("\n");


    {
        int n_attributes;
        UF_ATTR_part_attr_p_t atr;
        UF_ATTR_ask_part_attrs(objects1[0]->Tag(), &n_attributes, &atr);

        for (int i = 0; i < n_attributes; i++)
        {
            UF_UI_write_listing_window(("atr - " + (std::string)atr[i].title).c_str());
            UF_UI_write_listing_window("\n");
            UF_UI_write_listing_window(("atr - " + (std::string)atr[i].string_value).c_str());
            UF_UI_write_listing_window("\n");
            UF_UI_write_listing_window(("atr - " + (std::string)atr[i].value.value.string).c_str());
            UF_UI_write_listing_window("\n");
        }

    }*/
    /*int num_attributes;
    UF_ATTR_info_t* info;
    std::vector<NXOpen::DisplayableObject*>::iterator itfeat = objects1.begin();
    UF_ATTR_iterator_t iter;
    UF_ATTR_init_user_attribute_iterator (&iter);
    
    //while (iter. != objects1.end())
    //{
    //    NXOpen::DisplayableObject* section = itfeat.operator*();

        //UF_DISP_set_highlight(section->Tag(), 1);
        UF_ATTR_get_user_attributes (objects1[0]->Tag(), &iter, &num_attributes, &info );

        UF_UI_write_listing_window(("displayableObject1 - " + (std::string)info->string_value).c_str());
        UF_UI_write_listing_window("\n");

     //   itfeat.operator++(1);
    //}/**/
    //int indx = 0;
    //char  title[UF_ATTR_MAX_TITLE_BUFSIZE];
    //UF_ATTR_value_p_t value;
    //indx = UF_ATTR_cycle (part, &indx, UF_ATTR_any, title, value );

   
    
    int indx = 0;
    int type = UF_ATTR_any;
    char title[UF_ATTR_MAX_TITLE_LEN + 1] = "";
    UF_ATTR_value_t value;
    tag_t obj_tag = NULL_TAG;
    tag_t t1 = NULL_TAG;
    int count = 0;
    int count1 = 0;
    UF_PARAM_index_attribute_t attr; 
    
    char* string_value;
    logical has_attribute;
    UF_ATTR_get_string_user_attribute(part, "DB_PART_NAME", UF_ATTR_NOT_ARRAY, &string_value, &has_attribute);
    if (has_attribute)
    {
        //UF_UI_write_listing_window(("DB_PART_NAME ###- " + (std::string)string_value).c_str());
        //UF_UI_write_listing_window("\n");
        do
        {
            obj_tag = UF_OBJ_cycle_all(part, obj_tag);


            //UF_ATTR_value_t attr;
            //attr.value.string[UF_ATTR_MAX_STRING_BUFSIZE];

            //UF_ATTR_read_value(part, const_cast<char*>("DB_PART_NAME"), UF_ATTR_string, &attr);

            //UF_UI_write_listing_window(("Наименование - " + (std::string)attr.value.string + "\n").c_str());
            //UF_free(attr.value.string);


            try {
                int type2;
                int subtype2;
                UF_OBJ_ask_type_and_subtype(obj_tag, &type2, &subtype2);
                //UF_UI_write_listing_window(("type2 - " + std::to_string(type2)).c_str());
                //UF_UI_write_listing_window(("\nsubtype2 - " + std::to_string(subtype2)).c_str());
                //UF_UI_write_listing_window("\n");

                //if (type2 == UF_constraint_type && subtype2 == 2)
                //{
                //    UF_UI_write_listing_window("----UF_constraint_type----\n");
                //}

                if (type2 == 25 && subtype2 == 42)
                {

                    //NXOpen::UserDefinedObjects::UserDefinedObject* userDefinedObject22;
                    std::vector<NXOpen::Annotations::TitleBlock*> titleblocks1(1);
                    NXOpen::Annotations::TitleBlock* titleBlock1(dynamic_cast<NXOpen::Annotations::TitleBlock*>(NXObjectManager::Get(obj_tag))); //25 42
                    //NXOpen::Annotations::TitleBlock* titleBlock1(dynamic_cast<NXOpen::Annotations::TitleBlock*>(workPart->FindObject("HANDLE R-2982")));
                    titleblocks1[0] = titleBlock1;
                    NXOpen::Annotations::EditTitleBlockBuilder* editTitleBlockBuilder1;
                    editTitleBlockBuilder1 = workPart->DraftingManager()->TitleBlocks()->CreateEditTitleBlockBuilder(titleblocks1);
                    editTitleBlockBuilder1->SetCellValueForLabel("Label22", "");

                    NXString nx_str = string_value;// editTitleBlockBuilder1->GetCellValueForLabel("Label22");

                    //UF_UI_write_listing_window(("nx_str1 2- " + (std::string)nx_str.GetLocaleText()).c_str());
                    //UF_UI_write_listing_window("\n");

                    std::string str_lab = (std::string)nx_str.GetLocaleText();
                    //public: void SetCellValueForLabel ( const NXString & label  ,const NXString & value );
                    int cou = 0, num = 0;

                    //Убираем перенос строки если он есть и считаем количество пробелов
                    for (int i = 0; i < str_lab.size(); i++)
                    {
                        if (str_lab[i] == '\n')
                        {
                            str_lab[i] = ' ';
                        }
                        if (str_lab[i] == ' ')
                            num++;
                    }
                    //Установим перенос строки вместо пробела. Всегда берем средний пробел
                    for (int i = 0; i < str_lab.size(); i++)
                    {
                        if (str_lab[i] == ' ')
                        {
                            cou++;
                            if (cou == num / 2 && num > 3)
                                str_lab[i] = '\n';
                        }
                    }

                    UF_ATTR_value_t value;
                    value.type = UF_ATTR_string;
                    value.value.string = const_cast<char*>(str_lab.c_str());
                    UF_ATTR_assign(part, const_cast<char*>("COPY_DB_PART_NAME"), value);
                    //UF_MODL_update();
                    //editTitleBlockBuilder1->SetCellValueForLabel("Label22", str_lab);

                    //NXOpen::Annotations::TitleBlock* titleBlock11(dynamic_cast<NXOpen::Annotations::TitleBlock*>(workPart->FindObject("ENTITY 25 9 1")));

                    //UF_UI_write_listing_window(("titleBlock11- " + std::to_string(titleBlock11->Tag()) + "\n").c_str());
                    //UF_UI_write_listing_window(("titleBlock1- " + std::to_string(titleBlock1->Tag()) + "\n").c_str());

                    //NXOpen::Annotations::TitleBlock* titleBlock11(dynamic_cast<NXOpen::Annotations::TitleBlock*>(NXObjectManager::Get(obj_tag)));

                    NXOpen::Annotations::DefineTitleBlockBuilder* defineTitleBlockBuilder;
                    defineTitleBlockBuilder = workPart->DraftingManager()->TitleBlocks()->CreateDefineTitleBlockBuilder(titleBlock1);

                    NXOpen::Annotations::TitleBlockCellBuilderList* titleBlockCellBuilderList;
                    titleBlockCellBuilderList = defineTitleBlockBuilder->Cells();


                    NXOpen::TaggedObject* taggedObject;
                    taggedObject = titleBlockCellBuilderList->FindItem(0);

                    bool check = false;
                    std::vector<NXOpen::Annotations::TitleBlockCellBuilder*> GetContents = defineTitleBlockBuilder->Cells()->GetContents();
                    //UF_UI_write_listing_window(("GetContents.size() - " + std::to_string(GetContents.size()) + "\n").c_str());
                    for (int i = 0; i < GetContents.size(); i++)
                    {
                        if (i == 21)
                        {
                            taggedObject = titleBlockCellBuilderList->FindItem(i);
                            //UF_UI_write_listing_window(("taggedObject- " + std::to_string(taggedObject->Tag()) + "\n").c_str());
                            check = true;
                        }
                    }

                    NXOpen::Annotations::TitleBlockCellBuilder* titleBlockCellBuilder(dynamic_cast<NXOpen::Annotations::TitleBlockCellBuilder*>(taggedObject));
                    theSession->BeginTaskEnvironment();
                    if (check)
                        UF_TABNOT_set_cell_text(titleBlockCellBuilder->Cell()->Tag(), "<WRef1*0@COPY_DB_PART_NAME>");

                    NXOpen::Annotations::AssociativeText* associativeText1;
                    associativeText1 = workPart->Annotations()->CreateAssociativeText();
                    NXString text4;
                    text4 = associativeText1->GetPartAttributeText("COPY_DB_PART_NAME");//COPY_DB_PART_NAME
                    delete associativeText1;
                    titleBlockCellBuilder->EditCell(false, 3, "", "Label22", true);

                    theSession->DeleteUndoMarksSetInTaskEnvironment();
                    theSession->EndTaskEnvironment();
                    NXOpen::NXObject* nXObject4;
                    nXObject4 = defineTitleBlockBuilder->Commit();
                    defineTitleBlockBuilder->Destroy();



                    /*UF_UI_write_listing_window(("str_lab - " + str_lab).c_str());
                    UF_UI_write_listing_window("\n");

                    UF_UI_write_listing_window(("label - " + (std::string)nx_str.GetLocaleText()).c_str());
                    UF_UI_write_listing_window("\n");



                    std::vector<NXOpen::DisplayableObject*> objects1(1);
                    //NXOpen::DisplayableObject* displayableObject1(dynamic_cast<NXOpen::DisplayableObject*>(NXObjectManager::Get(obj_tag)));//160 2    218 2
                    NXOpen::DisplayableObject* displayableObject1(dynamic_cast<NXOpen::DisplayableObject*>(workPart->FindObject("HANDLE R-2225")));
                    objects1[0] = displayableObject1;


                    int type3;
                    int subtype3;
                    UF_OBJ_ask_type_and_subtype(objects1[0]->Tag(), &type3, &subtype3);
                    UF_UI_write_listing_window(("type3 - " + std::to_string(type3)).c_str());
                    UF_UI_write_listing_window(("\nsubtype3 - " + std::to_string(subtype3)).c_str());
                    UF_UI_write_listing_window("\n");


                    NXOpen::Annotations::TableEditSettingsBuilder* tableEditSettingsBuilder1;
                    tableEditSettingsBuilder1 = workPart->SettingsManager()->CreateTableEditSettingsBuilder(objects1);

                    std::vector<NXOpen::Drafting::BaseEditSettingsBuilder*> editsettingsbuilders1(1);
                    editsettingsbuilders1[0] = tableEditSettingsBuilder1;
                    workPart->SettingsManager()->ProcessForMultipleObjectsSettings(editsettingsbuilders1);

                    std::vector<NXOpen::Annotations::TableCellStyleBuilder::FitMethodType> fitmethods1(2);
                    fitmethods1[0] = NXOpen::Annotations::TableCellStyleBuilder::FitMethodTypeWrap;
                    fitmethods1[1] = NXOpen::Annotations::TableCellStyleBuilder::FitMethodTypeAutoSizeText;
                    tableEditSettingsBuilder1->TableCell()->SetFitMethods(fitmethods1);

                    std::vector<NXOpen::Annotations::TableCellStyleBuilder::FitMethodType> fitmethods2(3);
                    fitmethods2[0] = NXOpen::Annotations::TableCellStyleBuilder::FitMethodTypeWrap;
                    fitmethods2[1] = NXOpen::Annotations::TableCellStyleBuilder::FitMethodTypeAutoSizeText;
                    fitmethods2[2] = NXOpen::Annotations::TableCellStyleBuilder::FitMethodTypeOverwriteBorder;
                    tableEditSettingsBuilder1->TableCell()->SetFitMethods(fitmethods2);

                    NXOpen::NXObject* nXObject1;
                    nXObject1 = tableEditSettingsBuilder1->Commit();

                    tableEditSettingsBuilder1->Destroy();/**/


                }
            }
            catch (std::exception ex)
            {
                break;
                uc1601(const_cast<char*>("~ERROR~"), 1);
            };

            /*       int type;
                   int subtype;
                   UF_OBJ_ask_type_and_subtype(obj_tag, &type, &subtype);

                   if (type == UF_tabular_note_type && subtype == UF_tabular_note_section_subtype)
                   {
                       UF_UI_write_listing_window(("obj_tag - " + std::to_string(obj_tag)).c_str());
                       UF_UI_write_listing_window("\n");
                       UF_UI_write_listing_window(("type - " + std::to_string(type)).c_str());
                       UF_UI_write_listing_window("\n");
                       UF_UI_write_listing_window(("subtype - " + std::to_string(subtype)).c_str());
                       UF_UI_write_listing_window("\n");
                       char name[200];
                       UF_OBJ_ask_name(obj_tag, name);
                       UF_UI_write_listing_window(("name - " + (std::string)name).c_str());
                       UF_UI_write_listing_window("\n");

                       UF_ATTR_count_attributes (obj_tag, UF_ATTR_any, &count1);
                       UF_UI_write_listing_window(("count1 - " + std::to_string(count1)).c_str());
                       UF_UI_write_listing_window("\n");

                   }
           /*
                   /*
                   if (type == UF_parametric_text_type && subtype == UF_tabular_note_cell_subtype)
                   {


                       char *cell_text[200];
                       UF_TABNOT_ask_cell_text(obj_tag, cell_text);
                       //UF_UI_write_listing_window(("cell_text - " + (std::string)*cell_text).c_str());
                       //UF_UI_write_listing_window("\n");


                       std::string strin = (std::string)*cell_text;
                       auto slashPosition = strin.find_first_of("@");
                       strin.erase(strin.begin(), strin.begin() + slashPosition + 1); //с конца

                       std::string str_txt = (std::string)*cell_text;
                       auto slashPositionTxt = str_txt.find_first_of(">");
                       str_txt.erase(str_txt.begin(), str_txt.begin() + slashPositionTxt + 1); //с конца


                       std::string strin0 = (std::string)strin;
                       auto slashPosition0 = strin0.find_first_of(">");
                       strin0.erase(strin0.begin() + slashPosition0 + 1, strin0.end()); // с начала

                       std::string str_fn = (std::string)*cell_text;
                       auto slashPosition_fn = str_fn.find_first_of(">");
                       str_fn.erase(str_fn.begin() + slashPosition_fn + 1, str_fn.end()); // с начала
                       //UF_UI_write_listing_window(("&&&&&&&&&&&& - " + (std::string)str_txt).c_str());
                       //UF_UI_write_listing_window("\n");
                       //UF_UI_write_listing_window(("************ - " + (std::string)strin0).c_str());
                       //UF_UI_write_listing_window("\n");




                       if (strin0 == "FILENAME>")
                       {
                           bool check = false;
                           for (int i = 0; i < str_txt.size(); i++)
                           {
                               if (str_txt[i] == ' ')
                               {
                                   str_txt[i] = '\n';
                                   check = true;
                               }
                           }
                           if(check)
                           {
                               char* text[200] = { const_cast<char*>((str_fn + str_txt).c_str())};
                               UF_TABNOT_set_cell_text(obj_tag, *text);
                           }
                           /*UF_UI_write_listing_window("\n");
                           UF_UI_write_listing_window("****************************************************************************************\n");
                           UF_UI_write_listing_window("\n");


                           //Получить ширину столбца
                           double width = 0.0;
                           UF_TABNOT_ask_column_width(obj_tag, &width);
                           UF_UI_write_listing_window(("ширина столбца - " + std::to_string(width)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получает настройки ячейки по умолчанию
                           //UF_TABNOT_cell_prefs_t cell_prefs;
                           //UF_TABNOT_ask_default_cell_prefs(&cell_prefs);

                           //Получает настройки раздела по умолчанию.
                           //UF_TABNOT_ask_default_section_prefs

                           //Получить оцененный текст из ячейки табличной заметки
                           char* evaluated_text[500];
                           UF_TABNOT_ask_evaluated_cell_text(obj_tag, evaluated_text);
                           UF_UI_write_listing_window(("оцененный текст - " + (std::string)*evaluated_text).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получите информацию об объединенных ячейках.Если указанная ячейка является
                           //родительской для слияния(то есть это ячейка в диапазоне объединенных ячеек, содержащая
                           //текст), возвращает начальную и конечную строки и столбцы диапазона.
                           tag_t start_row = NULL_TAG;    // <O> Start row or NULL_TAG if cell is not merged
                           tag_t start_column = NULL_TAG; // <O> Start column or NULL_TAG if cell is not merged
                           tag_t end_row = NULL_TAG;      // <O> End row or NULL_TAG if cell is not merged
                           tag_t end_column = NULL_TAG;   // <O> End column or NULL_TAG if cell is not merged
                           UF_TABNOT_ask_merge_info(obj_tag, &start_row, &start_column, &end_row, &end_column);
                           UF_UI_write_listing_window(("начальный ряд - " + std::to_string(start_row)).c_str());
                           UF_UI_write_listing_window(("\nначальная колонка - " + std::to_string(start_row)).c_str());
                           UF_UI_write_listing_window(("\nконечный ряд - " + std::to_string(start_row)).c_str());
                           UF_UI_write_listing_window(("\nконечная колонка - " + std::to_string(start_row)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить количество столбцов в табличной заметке
                           int nm_columns = 0;
                           UF_TABNOT_ask_nm_columns(obj_tag, &nm_columns);
                           UF_UI_write_listing_window(("количество столбцов - " + std::to_string(nm_columns)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить количество строк заголовка в табличной заметке
                           int nm_header_rows = 0;
                           UF_TABNOT_ask_nm_header_rows(obj_tag, &nm_header_rows);
                           UF_UI_write_listing_window(("количество строк заголовка - " + std::to_string(nm_header_rows)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить количество строк в табличной заметке
                           int nm_rows = 0;
                           UF_TABNOT_ask_nm_rows(obj_tag, &nm_rows);
                           UF_UI_write_listing_window(("количество строк в табличной заметке - " + std::to_string(nm_rows)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить строку ячейки
                           tag_t row = NULL_TAG;
                           UF_TABNOT_ask_row_of_cell(obj_tag, &row);
                           UF_UI_write_listing_window(("строка ячейки - " + std::to_string(row)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить столбец в позиции относительно данного столбца
                           tag_t relative_column = NULL_TAG;
                           UF_TABNOT_ask_relative_column(row, 1, &relative_column);
                           UF_UI_write_listing_window(("столбец в позиции - " + std::to_string(relative_column)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить строку в позиции относительно данной строки
                           tag_t relative_row = NULL_TAG;
                           UF_TABNOT_ask_relative_row(row, 1, &relative_row);
                           UF_UI_write_listing_window(("строка в позиции - " + std::to_string(relative_row)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получите настройки цвета / шрифта / ширины для линии в заголовке строки.
                           int cfw[3];
                           UF_TABNOT_ask_row_head_cfw(row, cfw);
                           UF_UI_write_listing_window(("настройки цвета - " + std::to_string(cfw[0])).c_str());
                           UF_UI_write_listing_window(("\nнастройки шрифта - " + std::to_string(cfw[1])).c_str());
                           UF_UI_write_listing_window(("\nнастройки ширины - " + std::to_string(cfw[2])).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить высоту строки
                           double height = 0.0;
                           UF_TABNOT_ask_row_height(row, &height);
                           UF_UI_write_listing_window(("высота строки - " + std::to_string(height)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить часть строки
                           tag_t section = NULL_TAG;
                           UF_TABNOT_ask_section_of_row(row, &section);
                           UF_UI_write_listing_window(("часть строки - " + std::to_string(section)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить настройки раздела табличной заметки
                           UF_TABNOT_section_prefs_t section_prefs;
                           UF_TABNOT_ask_section_prefs(section, &section_prefs);
                           UF_UI_write_listing_window(("настройки раздела - " + std::string(section_prefs.continuation_note)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить табличную заметку столбца
                           tag_t tabular_note = NULL_TAG;
                           UF_TABNOT_ask_tabular_note_of_column(obj_tag, &tabular_note);
                           UF_UI_write_listing_window(("табличная заметка - " + std::to_string(tabular_note)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить табличную заметку раздела
                           tag_t tabular_note1 = NULL_TAG;
                           UF_TABNOT_ask_tabular_note_of_section(section, &tabular_note1);
                           UF_UI_write_listing_window(("табличная заметка раздела - " + std::to_string(tabular_note1)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить количество строк в разделе
                           int nm_rows1 = 0;
                           UF_TABNOT_ask_nm_rows_in_section(section, &nm_rows1);
                           UF_UI_write_listing_window(("количество строк в разделе - " + std::to_string(nm_rows1)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить количество разделов в табличной заметке
                           int nm_sections = 0;
                           UF_TABNOT_ask_nm_sections(tabular_note1, &nm_sections);
                           UF_UI_write_listing_window(("количество разделов в табличной заметке - " + std::to_string(nm_sections)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить n - й столбец в табличной заметке
                           tag_t column1 = NULL_TAG;
                           UF_TABNOT_ask_nth_column(tabular_note1, 0, &column1);
                           UF_UI_write_listing_window(("n - й столбец в табличной заметке - " + std::to_string(column1)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получает n - ю строку заголовка
                           tag_t row1 = NULL_TAG;
                           UF_TABNOT_ask_nth_header_row(tabular_note1, 0, &row1);
                           UF_UI_write_listing_window(("n - ю строку заголовка - " + std::to_string(row1)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить n - ю строку в табличной заметке
                           tag_t row2 = NULL_TAG;
                           UF_TABNOT_ask_nth_row(tabular_note1, 0, &row2);
                           UF_UI_write_listing_window(("n - ю строку в табличной заметке - " + std::to_string(row2)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить n - ю строку в разделе
                           tag_t row3 = NULL_TAG;
                           UF_TABNOT_ask_nth_row_in_section(tabular_note1, 0, &row3);
                           UF_UI_write_listing_window(("n - ю строку в разделе - " + std::to_string(row3)).c_str());
                           UF_UI_write_listing_window("\n");

                           //Получить n - й раздел в табличной заметке
                           tag_t section1 = NULL_TAG;
                           UF_TABNOT_ask_nth_section(tabular_note1, 0, &section1);
                           UF_UI_write_listing_window(("n - й раздел в табличной заметке - " + std::to_string(section1)).c_str());
                           UF_UI_write_listing_window("\n");












                           //***********************************************************************************
                           /*UF_UI_write_listing_window(("strin0 - " + (std::string)strin0).c_str());
                           UF_UI_write_listing_window("\n");

                           UF_PARAM_ask_param_attributes(count, &attr);
                           UF_UI_write_listing_window(("attr - " + (std::string)attr.name).c_str());
                           UF_UI_write_listing_window("\n");
                           count++;

                           UF_UI_write_listing_window(("obj_tag - " + std::to_string(obj_tag)).c_str());
                           UF_UI_write_listing_window("\n");


                           std::vector<NXOpen::DisplayableObject*> objects1(1);
                           NXOpen::DisplayableObject* displayableObject1(dynamic_cast<NXOpen::DisplayableObject*>(NXObjectManager::Get(obj_tag)));

                           objects1[0] = displayableObject1;
                           NXOpen::Annotations::TableEditSettingsBuilder* tableEditSettingsBuilder1;
                           tableEditSettingsBuilder1 = workPart->SettingsManager()->CreateTableEditSettingsBuilder(objects1);
                           std::vector<NXOpen::Drafting::BaseEditSettingsBuilder*> editsettingsbuilders1(1);
                           editsettingsbuilders1[0] = tableEditSettingsBuilder1;
                           workPart->SettingsManager()->ProcessForMultipleObjectsSettings(editsettingsbuilders1);
                           tableEditSettingsBuilder1->TableLettering()->SetGeneralTextSize(4.0);
                           NXOpen::NXObject* nXObject1;
                           nXObject1 = tableEditSettingsBuilder1->Commit();
                           tableEditSettingsBuilder1->Destroy();/**/
                           //   }
                          //}
                          //char name[200];
                          //UF_OBJ_ask_name(obj_tag, name);
                          //UF_UI_write_listing_window(("name - " + (std::string)name).c_str());
                          //UF_UI_write_listing_window("\n");
                          //UF_UI_write_listing_window("-------------------------------------\n");

                   /*       char* string_value;
                          logical has_attribute;
                          UF_ATTR_get_string_user_attribute(obj_tag, "DB_PART_NAME", UF_ATTR_NOT_ARRAY, &string_value, &has_attribute);
                          if (has_attribute)
                          {
                              UF_UI_write_listing_window(("DB_PART_NAME ###- " + (std::string)string_value).c_str());
                              UF_UI_write_listing_window("\n");
                          }



                          UF_ATTR_get_string_user_attribute(obj_tag, "SH_PART_NAME", UF_ATTR_NOT_ARRAY, &string_value, &has_attribute);
                          if (has_attribute)
                          {
                              UF_UI_write_listing_window(("SH_PART_NAME - " + (std::string)string_value).c_str());
                              UF_UI_write_listing_window("\n");
                          }

                          int n_attributes;
                          UF_ATTR_part_attr_p_t attributes;
                          UF_ATTR_ask_part_attrs_in_file("SH_PART_NAME", &n_attributes, &attributes);
                          if(n_attributes != 0)
                          {
                              UF_UI_write_listing_window(("n_attributes - " + std::to_string(n_attributes)).c_str());
                              UF_UI_write_listing_window("\n");
                          }

                          int title_type1;
                          UF_ATTR_find_attribute(obj_tag, UF_ATTR_any, const_cast<char*>("FILENAME"), &title_type1);
                          if (title_type1 != 0)
                          {
                              UF_UI_write_listing_window(("title_type1 - " + std::to_string(title_type1)).c_str());
                              UF_UI_write_listing_window("\n");
                          }
                          //FILENAME  <WRef1*0@FILENAME>
                          if(obj_tag != 0)
                          {

                              UF_ATTR_cycle(obj_tag, &indx, type, title, &value);
                              while (indx)
                              {
                                  UF_UI_write_listing_window(("title - " + (std::string)title).c_str());
                                  UF_UI_write_listing_window("\n");
                                  UF_UI_write_listing_window("****************************************\n");

                                  switch (value.type)
                                  {
                                  case UF_ATTR_bool:
                                      UF_UI_write_listing_window(("UF_ATTR_bool - " + std::to_string(value.value.boolean)).c_str());
                                      UF_UI_write_listing_window("\n");
                                      break;
                                  case UF_ATTR_integer:
                                      UF_UI_write_listing_window(("UF_ATTR_integer - " + std::to_string(value.value.integer)).c_str());
                                      UF_UI_write_listing_window("\n");
                                      break;
                                  case UF_ATTR_real:
                                      UF_UI_write_listing_window(("UF_ATTR_real - " + std::to_string(value.value.real)).c_str());
                                      UF_UI_write_listing_window("\n");
                                      break;
                                  case UF_ATTR_string:
                                      UF_UI_write_listing_window(("UF_ATTR_string - " + (std::string)value.value.string).c_str());
                                      UF_UI_write_listing_window("\n");
                                      UF_free(value.value.string);
                                      break;
                                  case UF_ATTR_reference:
                                      UF_UI_write_listing_window(("UF_ATTR_reference - " + (std::string)value.value.reference).c_str());
                                      UF_UI_write_listing_window("\n");
                                      UF_free(value.value.reference);
                                      break;
                                  default:	break;
                                  }



                                  UF_ATTR_cycle(obj_tag, &indx, type, title, &value);
                              }
                              //UF_free(value.value.string);
                          }/**/
        } while (obj_tag != NULL_TAG);/**/
    }

   
    /*char  title[UF_ATTR_MAX_TITLE_BUFSIZE];
    UF_ATTR_value_t value;
    value.type = UF_ATTR_any;
    int indx = 0;
    while (!(UF_ATTR_cycle(part, &indx, UF_ATTR_any, title, &value)) && (indx != 0))
    {
        switch (value.type)
        {
        case UF_ATTR_bool:
            UF_UI_write_listing_window(("UF_ATTR_bool - " + std::to_string(value.value.boolean)).c_str());
            UF_UI_write_listing_window("\n");
            break;
        case UF_ATTR_integer:
            UF_UI_write_listing_window(("UF_ATTR_integer - " + std::to_string(value.value.integer)).c_str());
            UF_UI_write_listing_window("\n");
            break;
        case UF_ATTR_real:
            UF_UI_write_listing_window(("UF_ATTR_real - " + std::to_string(value.value.real)).c_str());
            UF_UI_write_listing_window("\n");
            break;
        case UF_ATTR_string:
            UF_UI_write_listing_window(("UF_ATTR_string - " + (std::string)value.value.string).c_str());
            UF_UI_write_listing_window("\n");
            UF_free(value.value.string);
            break;
        case UF_ATTR_reference:
            UF_UI_write_listing_window(("UF_ATTR_reference - " + (std::string)value.value.reference).c_str());
            UF_UI_write_listing_window("\n");
            UF_free(value.value.reference);
            break;
        default:	break;
        }
    }

    {
        UF_initialize();
        tag_t object = 49586;
        int indx = 0;
        int type = UF_ATTR_any;
        char title[UF_ATTR_MAX_TITLE_LEN + 1] = "";
        UF_ATTR_value_t value;
        UF_ATTR_cycle(object, &indx, type, title, &value);
        UF_UI_open_listing_window();
        while (indx)
        {
            UF_UI_write_listing_window(title);
            UF_UI_write_listing_window("=");
            UF_UI_write_listing_window(value.value.string);
            UF_UI_write_listing_window("\n");
            UF_ATTR_cycle(object, &indx, type, title, &value);
        }
        UF_free(value.value.string);
        UF_terminate();
    }*/
}


void ufusr(char* param, int* retcod, int param_len)
{
    static unsigned char* c;
    c = { nxauthblock };

    int status = 0;
    status = UF_initialize();
    if (!status)
    {
        rename_title();
    }
    UF_terminate();
}

int ufusr_ask_unload(void)
{
    return (UF_UNLOAD_IMMEDIATELY);
}
