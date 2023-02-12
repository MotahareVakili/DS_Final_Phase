#include "home.h"
#include "ui_home.h"

home::home(QWidget *parent,QString id,QHash<QString,information>* info,QHash<QString,user>* pass) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);
    this->user_id=id;
    this->hash_map=info;
    this->hash_pass=pass;
    ui->tabWidget->setCurrentWidget(ui->profile);

    profile();

}

home::~home()
{
    delete ui;
}

void home::profile()
{
   information info= hash_map->value(user_id);
   ui->name->setText(info.name);
   ui->post->setText("Post: 0");
   ui->birth->setText("Date of Birth: "+info.dateOfBirth);
   ui->field->setText("Field: "+info.field);
   ui->uni_loc->setText("University Location: "+info.universityLocation);
   ui->wplace->setText("Work Place: "+info.workplace);
   ui->special->setText("Specialties:");
   for (QString s:info.specialties)
      ui->sp_txt->append(s);

}

void home::suggest(QString id, int n)
{
    if(n==6)
        return;

    for(QString Id:hash_map->value(id).connectionId)
    {
        if(suggestions.contains(Id))
        {
            if(suggestions.value(Id)>n)
                suggestions.insert(Id,n);
            continue;
        }

        else
            suggestions.insert(Id,n);
        suggest(Id,n+1);

    }

}



void home::new_member_suggest()
{
    information info_usr=hash_map->value(user_id);
    for( QString id:hash_map->keys())
    {
        if(suggestions.size()<20 && id!=user_id)
        {
            information info=hash_map->value(id);
            if(info.universityLocation==info_usr.universityLocation)
            {
                suggestions.insert(id,0);
                continue;
            }
            if(info.workplace==info_usr.workplace)
            {
                suggestions.insert(id,0);
                continue;
            }
            if(info.field==info_usr.field)
            {
                suggestions.insert(id,0);
                continue;
            }
            for(QString qs:info.specialties)
            {
                if(info_usr.specialties.contains(qs))
                {
                   suggestions.insert(id,0);
                   break;
                }
            }

        }
    }

}

void home::show_suggestions(int Coef_s, int Coef_f, int Coef_u, int Coef_w, int Coef_d)
{
    for(int i=0;i<ui->suggest->count();i++)
        delete ui->suggest->item(i);
    ui->suggest->clear();

    information info_u=hash_map->value(user_id);
    QMap<QString,int> map;
    for(QString id:suggestions.keys())
    {
        int score=0;
        if(suggestions.value(id)==0||suggestions.value(id)==1)
            continue;
        information info=hash_map->value(id);
        if(suggestions.value(id)>0)
        score=(20/suggestions.value(id))*Coef_d;
        if(info.field==info_u.field)
            score+=10*Coef_f;
        if(info.universityLocation==info_u.universityLocation)
            score+=10*Coef_u;
        if(info.workplace==info_u.workplace)
            score+=10*Coef_w;
        for(QString qs:info.specialties)
        {
            if(info_u.specialties.contains(qs))
            {
                score+=10*Coef_s;
                break;
            }
        }
        map.insert(info.name,score);
    }

   for(QString s:map.keys())
   {   if(ui->suggest->count()<20)
     {
       QListWidgetItem *item=new QListWidgetItem;
       item->setIcon(QIcon(":/image/p.png"));
       item->setText(s);
       QFont font;
       font.setPointSize(12);
       item->setFont(font);
       item->setSizeHint(QSize(30,30));
       ui->suggest->addItem(item);
       }
   }
}

void home::changed()
{
    on_tabWidget_currentChanged(1);
}



void home::on_tabWidget_currentChanged(int index)
{

  if(index==1)
    {

       ui->fname->setText(hash_map->value(user_id).name);
       ui->follow->setText("Following "+QString::number( hash_map->value(user_id).connectionId.size()));
       for(int i=0;i<ui->connections->count();i++)
           delete ui->connections->item(i);
       ui->connections->clear();
      for(QString s:hash_map->value(user_id).connectionId)
      {
          QListWidgetItem *item=new QListWidgetItem;
          item->setIcon(QIcon(":/image/p.png"));
          item->setText(hash_map->value(s).name);
          QFont font;
          font.setPointSize(12);
          item->setFont(font);
          item->setSizeHint(QSize(30,30));
          ui->connections->addItem(item);
      }
    }
   if(index==2)
   {
     prt=new class priority(this,& Coef_s, & Coef_f, & Coef_u,& Coef_w,& Coef_d);
       this->hide();
       prt->show();
       if(!hash_map->value(user_id).connectionId.isEmpty())
       {
           suggestions.clear();
           suggestions.insert(user_id,0);
           suggest(user_id,1);

           suggestions.clear();
            suggestions.insert(user_id,0);
           suggest(user_id,1);
           suggestions.clear();
            suggestions.insert(user_id,0);
           suggest(user_id,1);
           suggestions.clear();
            suggestions.insert(user_id,0);
           suggest(user_id,1);
           suggestions.clear();
            suggestions.insert(user_id,0);
           suggest(user_id,1);
           suggestions.clear();
            suggestions.insert(user_id,0);
           suggest(user_id,1);

       }
       else
           new_member_suggest();

      show_suggestions( Coef_s,  Coef_f,  Coef_u, Coef_w, Coef_d);
   }


}

void home::on_connections_itemDoubleClicked(QListWidgetItem *item)
{


    prfl=new class profile(this,hash_map,hash_pass->value(item->text()).id,user_id);
     connect(prfl,SIGNAL(mysignal()),this,SLOT(changed()));
    this->hide();
    prfl->show();
}

void home::on_suggest_itemDoubleClicked(QListWidgetItem *item)
{
    prfl=new class profile(this,hash_map,hash_pass->value(item->text()).id,user_id);
     connect(prfl,SIGNAL(mysignal()),this,SLOT(changed()));
    this->hide();
    prfl->show();
}


