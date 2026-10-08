import { NgModule, provideBrowserGlobalErrorListeners } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { AppRoutingModule } from './app-routing-module';
import { App } from './app';
import { UsersComponents } from './users/users.component';

@NgModule({
  declarations: [
    App, UsersComponents
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
],
  providers: [
    provideBrowserGlobalErrorListeners(),
  ],
  bootstrap: [App]
})
export class AppModule { }
